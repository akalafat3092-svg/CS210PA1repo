# Question 1:
Concat needs to use two lists of the same type because if it was required to use lists of different type you would need to iterate through each list and create new pointers based off the data in the lists to make them compatible, since ArrayLists and LinkedLists use memory differently

# Question 2:
The three you need alive the entire time are the preceding node, the current node, and the succeeding node. They respectively keep what came before, where we;re at right now, and the next node. You need these three alive because if one of them dies mid-loop the method might just forget about a whole portion of the list.

# Question 3:
For addAnywhere() the range is the front (index 0) to the space after the back of the list (index size) inclusively because you need to be able to add in front and the back (the back would be at the index after the last value, whose index is size - 1), for deleteAnywhere() the bounds are from the front (index 0) to the back (index size - 1) because that range covers all the items within the list and nothing more. For both if they are given a position out of bounds they just give an error saying that the passed in position is out of bounds then just returns without changing anything.

# Question 4:
We need to walk to the end of the list because usually the back would have a tail pointer but in our case it doesn't and our only entry point is the head pointer at the front. Since we do have a head pointer we can just directly insert and remove from the front with O(1) though. If there was a tail pointer then concat would have a better time complexity because we wouldn't have to walk to the end of the list and we could instead just insert and adjust and update the tail pointer as we go.

# Question 5:
For addAnywhere we have to shift towards the back before insertion so that there is an empty space to insert into. If we shifted to the front before insertion then we would get overwrite what was in the index preceding where we are inserting at and then when we insert we overwrite what is currently in the index we're inserting into, thus getting rid of two entire items and increasing size when the size stayed the same. If we inserted before shifting back, we would overwrite what's in that index and then leave an empty space at that index when we shift back.

# Question 6:
Lines 44 and 18 for the Uno Scene and Part One respectively. If the reverse were missing than visually the order would not get swapped and the reverse would be moot the game would continue in the old order.