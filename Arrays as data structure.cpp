#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int length;
    int* items;
public:  
    // constructor
    Array(int arrsize) {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    } 
    // get array elements
    void Fill() {
        int no_items;
        cout << "How many items you want to fill?\n";
        cin >> no_items;
        if (no_items > size) {
            cout << "The number your enter exceed\n";
            return;
        }
        else {
            cout << "Start Enter Your items: \n";
            for (int i = 0; i < no_items; i++)
                cin >> items[i];
            length += no_items;

        }
    }
    // Display array elements
    void Display() {
        cout << "\nDisplay Array Content: ";
        for (int i = 0; i < length; i++)
            cout << items[i] << " ";
        cout << endl;
    }
    // Get size function
    int GetSize() {
        return size;
    }
    // get length function
    int GetLength() {
        return length;
    }
    // get an element searching in an array
    int Research(int key) {
        int index=-1;
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                return i;
                index = i;
            }
        }
        if (index == -1)
            return -1;
    }
    // adding an element in the last of array
    void Append(int element) {
        if(length < size){
        items[length] = element;
        length++;
        }
        else {
            cout << "Array is Full..!" << endl;
        }
    }
    // inserting element in a determinant position in the array
    void Insert(int index, int element) {
        index -= 1;
        if (index >= 0 && length < size && index < size) {
            for (int i = length; i > index; i--) {
                items[i] = items[i - 1];
            }
            items[index] = element;
            length++;
        }
        else {
            cout << "The array is Full..! or check your value again ..! " << endl;
        }
    }
    // Delete Element from array
    void Delete(int index) {
        index -= 1; // to make it more clear for user it will delete the position not index
        if(index >= 0 && index < size )
            for (int i = index; i < length; i++) {
            items[i] = items[i + 1];
        }
        length--;
    }
    // Enlarge function to change the size for the array to large size only
    void EnLarge(int newsize) {
        if (newsize <= size) {
            cout << "New size must be larger than current size!" << endl;
            return;
        }
        else {
            size = newsize;
            int oldlength = length;
            // length = 0;
            int* oldarray = items;
            items = new int[newsize];
            for (int i = 0; i < oldlength; i++) {
                items[i] = oldarray[i];
                // length++;
            }
            delete[] oldarray;
        }  
    }
    // Merge two arrays 
    void Merge(Array other) {
        int newsize = size + other.GetSize();
        size = newsize;
        int* old = items;
        items = new int[size];
        for (int i = 0; i < length; i++) {
            items[i] = old[i];
        }
        int j = length;
        for (j =0; j < other.GetSize(); j++) {
            items[length++] = other.items[j];
        }
        /*
        for (int i = 0; i < other.GetSize(); i++) {
            items[j++] = other.items[i];
            length++;
        }
        */
        delete[]old;
        /*
        int *oldarray = items;
        size = arraylength + length;
        items = new int[size];
        for (int i = 0; i < length; i++) {
            items[i] = oldarray[i];
        }
        for (int i = length; i < size; i++) {
            items[i] = newarray[i];
        }*/
    }
};

int main()
{  
    
    /*
    int arrsize;
    cout << "Enter Array size: \n";
    cin >> arrsize;
    Array arr1(arrsize); */
    //  Filling the array
    /*arr1.Fill();*/
    //  Search ...@
    /* int serchval;
    cout << "We will get your Value what is it?! " << endl;
    cin >> serchval;
    if (arr1.Research(serchval) == -1)
        cout << "Not here!" << endl;
    else
        cout << "Your value at the" << arr1.research(serchval)+1 << " position" << endl;
    */
    //  Appending .. 
    /*int addelement;
    cout << "Add Your element to array: ";
    cin >> addelement;
    arr1.Append(addelement);*/
    // Insertion
    /*int insertposition, insertelement;
    cout << "Add your element in any position, Enter the Position: " << endl;
    cin >> insertposition;
    cout << "Enter the Element: ";
    cin >> insertelement;
    arr1.Insert(insertposition, insertelement);*/
    //  Delete ... 
    /*int deleteElement;
    cout << "Enter The Index you need delete: ";
    cin >> deleteElement;
    arr1.Delete(deleteElement);*/
    //  Knowing the size and length of the array
    /*cout << "Length: " << arr1.GetLength() << "\t" << "Size: " << arr1.GetSize();*/
    //  Large the size for the array but you can't fill it after it only your old items will in it
    /*
    cout << "Change to new array size! Enter new array size: " << endl;
    int newarraysize;
    cin >> newarraysize;
    arr1.EnLarge(newarraysize);
    //  Displaing ...  
    arr1.Display();
    //  Knowing the size and length of the array
    cout << "Length: " << arr1.GetLength() << "\t" << "Size: " << arr1.GetSize();
    */
    //  Merge two arrays 
    /*Array other(3);
    cout << "Enter other Array items: \n";
    other.Fill();
    arr1.Merge(other);
    cout << "Length: " << arr1.GetLength() << "\t" << "Size: " << arr1.GetSize();
    arr1.Display();*/

    return 0;
}
