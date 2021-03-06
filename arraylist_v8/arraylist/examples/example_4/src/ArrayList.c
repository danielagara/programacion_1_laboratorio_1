#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);
int resizeDown(ArrayList* pList);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList = (ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)//LISTO
{
    int returnAux = -1;

    if(pList!=NULL && pElement!=NULL)
    {
        if(pList->size==pList->reservedSize)
        {
            resizeUp(pList);
        }

        pList->pElements[pList->size]=pElement;
        pList->size++;
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)//LISTO
{
    int returnAux = -1;
    if(pList==NULL)
    {
        returnAux=-1;
    }
    else if(pList!=NULL)
    {
        free(pList->pElements);
        free(pList);
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Length arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList) //LISTO
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        returnAux=pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index)//LISTO
{
    void* returnAux = NULL;
    int length=al_len(pList);
    if(pList!=NULL)
    {
        if(index<length && index>=0)
        {
            returnAux=pList->pElements[index];
        }
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if pList list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)//LISTO
{
    int returnAux = -1;
    int i;

    if(pList!=NULL && pElement!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            if(pElement==pList->pElements[i])
            {
                returnAux=1;
                break;
            }
            else if(pElement!=pList->pElements[i])
            {
                returnAux=0;
            }
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)//LISTO
{
    int returnAux = -1;
    int length=al_len(pList);

    if(pList!=NULL && pElement!=NULL)
    {
        if(index<=length && index>=0)
        {
            if(index==length)
            {
                pList->add(pList, pElement);
            }
            else
            {
                pList->pElements[index]=pElement;
            }
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)//LISTO
{
    int returnAux = -1;


    if(pList!=NULL)
    {
        int length=al_len(pList);

        if(length>0)
        {
            if(index<length && index>=0)
            {
                if(contract(pList,index)!=-1)
                {
                    returnAux=0;
                }
            }
        }
    }


    return returnAux;
}



/** \brief Removes all of the elements from pList list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList) //LISTO
{
    int returnAux = -1;
    void** AUXpList;
    if(pList!=NULL)
    {
        pList->size=0;
        pList->reservedSize=AL_INCREMENT;
        AUXpList=(void**)realloc(pList->pElements,sizeof(void*)*pList->reservedSize);

        returnAux=0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in pList list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)//LISTO
{
    ArrayList* returnAux = NULL;

    if(pList!=NULL)
    {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {
            return returnAux;
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)//LISTO
{
    int returnAux = -1;
    int i;

    if(pList!=NULL && pElement!=NULL)
    {
        int length=al_len(pList);
        if(index<=length && index>=0)
        {
            if(pList->size==pList->reservedSize)
            {
                resizeUp(pList);
            }
                if(index==pList->size)
                {
                    al_add(pList,pElement);
                }
                else
                {
                    for(i=pList->size-1;i>=index;i--)
                    {
                        al_set(pList,i-1,pList->pElements[i]);
                    }
                    al_set(pList,index,pElement);
                    returnAux=0;
                }
            }

    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement) //LISTO
{
    int returnAux = -1;
    int i;

    if(pList!=NULL && pElement!=NULL)
    {
        int length=al_len(pList);
        for(i=0;i<length;i++)
        {
            if(pElement==pList->pElements[i])
            {
                returnAux=i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if pList list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)//LISTO
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        int length=al_len(pList);
        if(length==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)//LISTO
{
    void* returnAux = NULL;

    if(pList!=NULL)
    {
        int length=al_len(pList);
        if(index<length && index>=0)
        {
            returnAux=al_get(pList,index);
            al_remove(pList,index);
        }
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)//LISTO
{
    void* returnAux = NULL;
    void* newpList;
    int i;

    if(pList!=NULL)
    {
        int length=al_len(pList);
        if(from>=0 && to>0 && from<=length && to<=length && from<to)
        {
            if ((newpList=al_newArrayList()) != NULL)
            {
                for(i=from;i<to;i++)
                {
                    al_add(newpList,pList->pElements[i]);
                }
                returnAux=newpList;
            }
        }

    }

    return returnAux ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)//LISTO
{
    int returnAux = -1;
    int i;

    if(pList!= NULL && pList2!=NULL)
    {
        returnAux=1;
        for(i=0;i<=pList2->size;i++)
        {
            if(al_contains(pList,pList2->pElements[i])!=1)
            {
                returnAux=0;
            }
            break;
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)//LISTO
{
    int returnAux = -1;
    void* AUXpElement;
    int i,j;

    if(pList!=NULL && pFunc!=NULL)
    {
        if(order==0 || order==1)
        {
            int length=al_len(pList);
            returnAux=0;
            for(i=0;i<length-1;i++)
            {
                for(j=i+1;j<length;j++)
                {
                    if((pFunc(pList->pElements[i],pList->pElements[j]))==1 && order==1)
                    {
                        AUXpElement=pList->pElements[i];
                        pList->pElements[i]=pList->pElements[j];
                        pList->pElements[j]=AUXpElement;
                    }
                    if((pFunc(pList->pElements[i],pList->pElements[j]))==-1 && order==0)
                    {
                        AUXpElement=pList->pElements[j];
                        pList->pElements[j]=pList->pElements[i];
                        pList->pElements[i]=AUXpElement;
                    }
                }
            }


        }
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList) //LISTO
{
    void** AUXpElements;
    int returnAux = -1;

    if(pList->size==pList->reservedSize)
    {
        pList->reservedSize+=AL_INCREMENT;
        AUXpElements=(void**)realloc(pList->pElements,sizeof(void*)*pList->reservedSize);
        if(AUXpElements!=NULL)
        {
            pList->pElements=AUXpElements;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)//LISTO
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        int length=al_len(pList);
        if(index<=length && index>=0)
        {
            if(pList->size==pList->reservedSize)
            {
                resizeUp(pList);
            }
        }
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)//LISTO
{
    int returnAux = -1;
    int i;
    int length=al_len(pList);
    if(pList!=NULL)
    {
        if(index<length && index>=0)
        {
            for(i=index;i<pList->size;i++)
            {
                al_set(pList,i,pList->pElements[i+1]);
            }
            pList->size--;
            returnAux=0;
            if(pList->reservedSize-pList->size > AL_INCREMENT)
            {
                resizeDown(pList);
            }
        }
    }
    return returnAux;
}

/** \brief Resize down an array list
 *
 * \param pList ArrayList* Pointer to arrayList
 * \return (-1) if error, (0) if ok
 *
 */
int resizeDown(ArrayList* pList)//LISTO
{
    int returnAux = -1;
    void** AUXpElements;
    if(pList->reservedSize-pList->size > AL_INCREMENT)
    {

        AUXpElements=(void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize-AL_INCREMENT));
        if(AUXpElements!=NULL)
        {
            pList->pElements=AUXpElements;
            pList->reservedSize=pList->reservedSize-AL_INCREMENT;
            returnAux=0;
        }
    }
    return returnAux;

}
