#pragma once
/*
	blinky slot quick sort
	no-swap version of quicksort
*/
template <class T>
void bsqs(T* l, T* r)
{
	if (l >= r) return;	//here we actually may to sort few elements arrays other way
	T* _l = l;//left bound
	T* _r = r;//right bound
	T pivot = *(_l++);//extract pivot to compare other elements with
	//here we get a slot in the place was holded by pivot
	bool slot_left = true; //flag showing that the slot is placed left side of left bound
	while (_l <= _r)
	{
		if (slot_left)
		{
			T tmp = *(_r);//check right element
			if (tmp < pivot)//if less than pivot
			{
				*(_l - 1) = tmp;//put it to the slot
				slot_left = false;//now we get a new slot where previous element were placed
			}
			//if bigger - just leave it there
			--_r;//shift right bound
		}
		else//right slot
		{
			T tmp = *(_l);
			if (tmp > pivot)
			{
				*(_r + 1) = tmp;
				slot_left = true;
			}
			++_l;
		}
	}
	T* slot = slot_left ? _r : _l;
	*slot = pivot;//placing pivot to the remaining slot
	bsqs(l, slot - 1);//recursively sorting right and left subarrays
	bsqs(slot + 1, r);
}