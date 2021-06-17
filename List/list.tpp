
template<typename T>
     List<T>::List(const T& data) {
         m_head = new list_node<T>;
         m_head->m_data = data;
         m_head->next = nullptr;
         ++size;
     } 
template<typename T>
     List<T>::~List() {
         list_node<T>* cur = m_head;
         while(m_head->next != nullptr)
         {
            m_head = cur->next;
            delete cur;
            cur = m_head; 
         }
         delete m_head;
         m_head = nullptr;
     }
template<typename T>
    void List<T>::push_front(const T& data)
    {
        list_node<T>* node = new list_node<T>;
        node->m_data = data;
        if(m_head == nullptr) {
            m_head = node;
            node->next = nullptr;
        }
        else {
            node->next = m_head;
            m_head = node;
        }
        ++size;
    }
template<typename T>
    void List<T>::push_back(const T& data){
        list_node<T>* node = new list_node<T>;
        node->m_data = data;
        list_node<T>* cur = m_head;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = node;
        ++size;
    }
template<typename T>
     void List<T>::insert(const T& data, int pos){
        list_node<T>* node = new list_node<T>;
        node -> m_data = data;
        if(m_head == nullptr && pos == 1)
        {
             push_front(data);
        }    
        if (pos == 1) {
            push_front(data);
        }
        list_node<T>* cur = m_head;
        for (int i = 1; i < pos - 1; ++i) 
        {
            if (cur->next != nullptr) {
            cur = cur->next;
            }
            if (cur->next != nullptr) {
                node->next = cur->next;
                cur->next = node;
            }
            else {
                push_back(data);
            }
        }
        ++size;
    } 
template<typename T>
    void List<T>::remove(int pos){
        list_node<T>* cur = m_head;
        list_node<T>* tmp;
        if(m_head == nullptr)
        {
             std::cout<<"There is nothing to delete.";
             return;
        }
        if (m_head != nullptr && pos == 1) {
            m_head = m_head->next;
            delete cur;
        }
        for (int i = 1; i < pos ; ++i)
        {
            if (cur->next != nullptr) {
            tmp = cur;
            cur = cur->next;
            }
        }
        if (cur->next != nullptr) {
            tmp->next=cur->next;
            delete cur;
        }
        else {
            tmp->next = nullptr;
            delete cur;
        }
        --size;
    }



