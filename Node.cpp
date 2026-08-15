#include <unordered_map>
#include <vector>
#include <iostream>

class Node{
    private:
        Node* next;
        int value;


    public:
        Node(int value) : value(value), next(nullptr) {}

        Node* getNext(){
            return next;
        }
        int getValue(){
            return value;
        }

        void setNext(Node* next){
            this->next = next;
        }

        void setValue(int value){
            this->value = value;
        }
};


class LinkedList{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}

        Node* getHead(){
            return head;
        }



        void add(int value){
            if(head == nullptr){
                head = new Node(value);
                return;
            }
            Node* temp = head;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
            }

            temp->setNext(new Node(value));
            
        }

        std::vector<int> twoSum(int target){
            std::unordered_map<int, int> map;

            Node* current = head;
            int i = 0;
            int value = 0;
            while(current != nullptr){
                int needed = value - target;
                
                if(map.find(needed) != map.end()){                    
                    return {i, map[needed]};
                }
                map[value] = i;

                i++;
                current = current->getNext();
                // struct pointer its just ->getNext no ()
            }
            return {-1, -1};

        }


        bool isPalindrome(Node* head){
            if(head == nullptr || head->getNext() == nullptr){
                return true;
            }
            // get middle node



            Node* fast = head;
            Node* mid = head;
            // mid is slow
            while(fast != nullptr && fast->getNext() != nullptr){
                fast = fast->getNext()->getNext();
                mid = mid->getNext();
            }
            Node* firstHalf = head;

            // if we have bad. func should return true...

            // mid -> a

            Node* prev = nullptr;
            Node* current = mid;
            Node* next = nullptr;

            // a now points to null ptr
            // prev a then b points to a
            // so string becomes.... [b] [ba] / two parts

            while(current != nullptr){
                next = current->getNext();

                current->setNext(prev);
                prev = current;

                current = next;
            }
            Node* secondHalf = prev;
            // 
            while(secondHalf != nullptr){
                if(firstHalf->getValue() != secondHalf->getValue()) return false;

                firstHalf = firstHalf->getNext();
                secondHalf = secondHalf->getNext();
            }

            return true;






            // reverse mid -> end
            // check
        }



        bool cycleDetection(Node* node){
            Node* fast = node;
            Node* slow = node;

            while(fast != nullptr && fast->getNext() != nullptr){
                fast = fast->getNext()->getNext();
                slow = slow->getNext();
                if(slow == fast){
                    return true;
                }
            }

            return false;

        }


        Node* getNthNodeFromEnd(Node* node, int n){
            Node* fast = node;
            Node* slow = node;

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

        int removeNthNodeFromEnd(Node* node, int n){
            Node* dummy = new Node(0);
            dummy->setNext(node);

            Node* fast = dummy;
            Node* slow = dummy;

            for(int i = 0; i < n; i++){
                if(fast == nullptr) return dummy->getNext()->getValue();
                fast = fast->getNext();
            }
            while(fast->getNext() != nullptr){
                slow = slow->getNext();
                fast = fast->getNext();
            }

            // now slow->getNext() is the one we want to delete
            Node* nthNode = slow->getNext();
            int nthValue = nthNode->getValue();
            slow->setNext(slow->getNext()->getNext());
            
            delete nthNode;
            return nthValue;
        }


        void bubbleSort(Node* node){
            if(node == nullptr || node->getNext() == nullptr) return;

            bool swapped;

            do{
                swapped = false;
                Node* current = node;

                while(current->getNext() != nullptr){
                    int value1 = current->getValue();
                    int value2 = current->getNext()->getValue();

                    if(value1 > value2){
                        current->setValue(value2);
                        current->getNext()->setValue(value1);
                        swapped = true;
                    }
                }
            }while(swapped);
        }

    Node* insertionSort(Node* node){
        if(node == nullptr || node->getNext() == nullptr) return node;

        Node* dummy = new Node(0);
        Node* curr = node;

        while(curr != nullptr){
            Node* nextNode = curr->getNext();

            Node* prev = dummy;

            while(prev->getNext() != nullptr && prev->getNext()->getValue() < curr->getValue()){
                prev = prev->getNext();
            }

            curr->setNext(prev->getNext());
            prev->setNext(curr);

            curr = nextNode;
        }
        Node* sortedHead = dummy->getNext();
        delete dummy;
        return sortedHead;
    }
};







int main(){
    LinkedList list;
    list.add('2');
    list.add('1');
    list.add('2');
    list.add('2');

    if(list.isPalindrome(list.getHead())){
        std::cout << "\nTrue!\n";
    }else{
        std::cout << "\nFalse!\n";
    }

    return 0;
}