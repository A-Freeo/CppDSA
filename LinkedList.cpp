#include <unordered_map>
#include <vector>
#include <iostream>
#include "Node.hpp"

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList() : head(nullptr) {}

        Node<T>* getHead(){
            return head;
        }

        // --- Core operations ---

        void add(T value){
            if(head == nullptr){
                head = new Node<T>(value);
                return;
            }
            Node<T>* temp = head;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
            }

            temp->setNext(new Node<T>(value));

        }

        // Insert value at 1-indexed position n (n <= 1 makes it the new head).
        // If n is past the end, the value is appended at the tail.
        void insert(T value, int n){
            Node<T>* newNode = new Node<T>(value);
            if(head == nullptr || n <= 1){
                newNode->setNext(head);
                head = newNode;
                return;
            }
            Node<T>* temp = head;
            for(int i = 0; i < n - 2 && temp->getNext() != nullptr; i++){
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }

        // --- Reversal ---

        Node<T>* reverse(Node<T>* node){
            if(node == nullptr || node->getNext() == nullptr){
                return node;
            }
            Node<T>* curr = node;
            Node<T>* next = nullptr;
            Node<T>* prev = nullptr;
            while(curr != nullptr){
                next = curr->getNext();
                curr->setNext(prev);

                prev = curr;
                curr = next;
            }
            return prev;
        }

        Node<T>* reverseRecursive(Node<T>* node){
            if(node == nullptr || node->getNext() == nullptr) return node;

            Node<T>* newHead = reverseRecursive(node->getNext());
            node->getNext()->setNext(node);
            node->setNext(nullptr);

            return newHead;
        }

        // Fast/slow walk: when fast falls off the end, mid sits at the
        // start of the second half (or the center node if the list is odd).
        Node<T>* middleNode(Node<T>* node){
            Node<T>* fast = node;
            Node<T>* mid = node;
            while(fast != nullptr && fast->getNext() != nullptr){
                fast = fast->getNext()->getNext();
                mid = mid->getNext();
            }
            return mid;
        }

        bool isPalindrome(Node<T>* node){
            if(node == nullptr || node->getNext() == nullptr){
                return true;   // empty or single node is always a palindrome
            }

            // Phase A: find the middle, then reverse the second half.
            Node<T>* mid = middleNode(node);
            Node<T>* firstHalf = node;

            Node<T>* prev = nullptr;
            Node<T>* current = mid;
            Node<T>* next = nullptr;
            while(current != nullptr){
                next = current->getNext();   // save the rest
                current->setNext(prev);      // flip this arrow backwards
                prev = current;              // prev creeps forward
                current = next;              // move on
            }
            Node<T>* secondHalf = prev;      // prev is the new head of the reversed half

            // Phase B: walk both halves inward; any mismatch means not a palindrome.
            while(secondHalf != nullptr){
                if(firstHalf->getValue() != secondHalf->getValue()) return false;

                firstHalf = firstHalf->getNext();
                secondHalf = secondHalf->getNext();
            }

            return true;
        }

        // --- Queries ---

        std::vector<int> twoSum(T target){
            std::unordered_map<T, int> map;

            Node<T>* current = head;
            int i = 0;
            while(current != nullptr){
                T value = current->getValue();
                T needed = target - value;

                if(map.find(needed) != map.end()){
                    return {i, map[needed]};
                }
                map[value] = i;

                i++;
                current = current->getNext();
            }
            return {-1, -1};

        }

        bool cycleDetection(Node<T>* node){
            Node<T>* fast = node;
            Node<T>* slow = node;

            while(fast != nullptr && fast->getNext() != nullptr){
                fast = fast->getNext()->getNext();
                slow = slow->getNext();
                if(slow == fast){
                    return true;
                }
            }

            return false;

        }

        Node<T>* getNthNodeFromEnd(Node<T>* node, int n){
            Node<T>* fast = node;
            Node<T>* slow = node;

            for(int i = 0; i < n; i++){
                if(fast == nullptr) return nullptr;
                fast = fast->getNext();
            }
            while(fast != nullptr){
                slow = slow->getNext();
                fast = fast->getNext();
            }

            return slow;
        }

        T removeNthNodeFromEnd(Node<T>* node, int n){
            Node<T>* dummy = new Node<T>(T{});
            dummy->setNext(node);

            Node<T>* fast = dummy;
            Node<T>* slow = dummy;

            for(int i = 0; i < n; i++){
                if(fast == nullptr) return dummy->getNext()->getValue();
                fast = fast->getNext();
            }
            while(fast->getNext() != nullptr){
                slow = slow->getNext();
                fast = fast->getNext();
            }

            // now slow->getNext() is the one we want to delete
            Node<T>* nthNode = slow->getNext();
            T nthValue = nthNode->getValue();
            slow->setNext(slow->getNext()->getNext());

            delete nthNode;
            return nthValue;
        }

        // --- Sorting ---

        // In-place bubble sort: swap values, so the head node never changes.
        void bubbleSort(Node<T>* node){
            if(node == nullptr || node->getNext() == nullptr) return;

            bool swapped;

            do{
                swapped = false;
                Node<T>* current = node;

                while(current->getNext() != nullptr){
                    T value1 = current->getValue();
                    T value2 = current->getNext()->getValue();

                    if(value1 > value2){
                        current->setValue(value2);
                        current->getNext()->setValue(value1);
                        swapped = true;
                    }
                    current = current->getNext();
                }
            }while(swapped);
        }

        // In-place insertion sort: for each node, slide its value back into
        // the sorted prefix, shifting larger values forward. Head is stable.
        void insertionSort(Node<T>* node){
            if(node == nullptr || node->getNext() == nullptr) return;

            for(Node<T>* i = node->getNext(); i != nullptr; i = i->getNext()){
                T key = i->getValue();

                // find the first node in the sorted prefix whose value > key
                Node<T>* p = node;
                while(p != i && p->getValue() <= key){
                    p = p->getNext();
                }

                // shift values from p up to i forward by one, then drop key at p
                T carry = key;
                for(Node<T>* cur = p; cur != i->getNext(); cur = cur->getNext()){
                    T tmp = cur->getValue();
                    cur->setValue(carry);
                    carry = tmp;
                }
            }
        }

        Node<T>* mergeTwoLists(Node<T>* node1, Node<T>* node2){
            bubbleSort(node1);
            bubbleSort(node2);
            Node<T>* temp1 = node1;
            Node<T>* temp2 = node2;

            Node<T>* dummy = new Node<T>(T{});
            Node<T>* tail = dummy;

            while(temp1 != nullptr && temp2 != nullptr){
                if(temp1->getValue() < temp2->getValue()){
                    tail->setNext(temp1);
                    temp1 = temp1->getNext();
                }else{
                    tail->setNext(temp2);
                    temp2 = temp2->getNext();
                }
                tail = tail->getNext();
            }
            while(temp1 != nullptr){
                tail->setNext(temp1);
                temp1 = temp1->getNext();
                tail = tail->getNext();
            }
            while(temp2 != nullptr){
                tail->setNext(temp2);
                temp2 = temp2->getNext();
                tail = tail->getNext();
            }
            return dummy->getNext();
        }


};


int main(){
    LinkedList<int> list;
    list.add(2);
    list.add(1);
    list.add(2);
    list.add(2);

    if(list.isPalindrome(list.getHead())){
        std::cout << "\nTrue!\n";
    }else{
        std::cout << "\nFalse!\n";
    }

    return 0;
}
