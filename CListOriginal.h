#pragma once

template <typename T>
struct tListNode
{
    T data;
    tListNode<T> *pNext;
    tListNode<T> *pPrev;

    tListNode()
        : data(), pPrev(nullptr), pNext(nullptr)
    {
    }

    //  초기화를 받아온 인자를 사용하겠다는 것.오버로딩
    tListNode(const T &_data, tListNode<T> *_pPrev, tListNode<T> *_pNext)
        : data(_data), pPrev(_pPrev), pNext(_pNext)
    {
    }
};

template <typename T>
class CList
{
private:
    tListNode<T> *m_pHead;
    tListNode<T> *m_pTail;
    int m_iCount;

public: // 생성자 소멸자 선언
    CList();
    ~CList();

public:
    void push_back(const T &_data);
    void push_front(const T &_data);
};

template <typename T>
CList<T>::CList()
    : m_pHead(nullptr),
      m_pTail(nullptr),
      m_iCount(0){

      };

template <typename T>
void CList<T>::push_back(const T &_data)
{
    // 입력된 데이터를 저장할 노드를 동적할당함
    tListNode<T> *pNewNode = new tListNode<T>(_data, nullptr, nullptr);

    if (nullptr == m_pHead)
    {
        this->m_pHead = pNewNode;
        this->m_pTail = pNewNode;
    }
    else
    {
        m_pTail->pNext = pNewNode;
        pNewNode->pPrev = m_pTail;
        m_pTail = pNewNode;
    }
    //  데이터 개수 증가
    ++m_iCount;
}

template <typename T>
void CList<T>::push_front(const T &_data)
{
    //  새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움
    tListNode<T> *pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

    //  현재 헤드노드의 이전노드 주소값을 새로 생성된 노드의 주소로 채움
    m_pHead->pPrev = pNewNode;

    //  리스트가 새로 생성된 노드를 새로운 헤드주소로 갱신한다.
    m_pHead = pNewNode;

    // 데이터 개수 증가
    ++m_iCount;
}

template <typename T>
CList<T>::~CList()
{
    tListNode<T> *pDeletNode = m_pHead;
    // 다음이 존재하지 않을 때까지 메모리를 해제해주는
    // 동적할당에서 관리하던 노드들이 삭제가 된다.
    while (pDeletNode)
    {
        tListNode<T> *pNext = pDeletNode->pNext;
        delete (pDeletNode);
        pDeletNode = pNext;
    }
}
