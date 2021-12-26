//-------------------------------------------------------------------
// Raw iterator with random access
//-------------------------------------------------------------------
template<typename blDataType>
class blRawIterator
{
public:

    using iterator_category = std::random_access_iterator_tag;
    using value_type = blDataType;
    using difference_type = std::ptrdiff_t;
    using pointer = blDataType*;
    using reference = blDataType&;

public:

    blRawIterator(blDataType* ptr = nullptr){m_ptr = ptr;}
    blRawIterator(const blRawIterator<blDataType>& rawIterator) = default;
    ~blRawIterator(){}

    blRawIterator<blDataType> & operator= (const blRawIterator<blDataType>& rawIterator) = default;
    blRawIterator<blDataType> & operator= (blDataType* ptr){m_ptr = ptr; return (*this);}

    operator bool() const { return m_ptr != nullptr ? true : false;}

    bool operator== (const blRawIterator<blDataType>& rawIterator) const {return (m_ptr == rawIterator.getConstPtr());}
    bool operator!= (const blRawIterator<blDataType>& rawIterator) const {return (m_ptr != rawIterator.getConstPtr());}

    blRawIterator<blDataType>& operator+= (const difference_type& movement) {m_ptr += movement;return (*this);}
    blRawIterator<blDataType>& operator-= (const difference_type& movement) {m_ptr -= movement;return (*this);}
    blRawIterator<blDataType>& operator++ (){++m_ptr;return (*this);}
    blRawIterator<blDataType>& operator-- (){--m_ptr;return (*this);}
    blRawIterator<blDataType> operator++ (int){auto temp(*this);++m_ptr;return temp;}
    blRawIterator<blDataType> operator-- (int){auto temp(*this);--m_ptr;return temp;}
    blRawIterator<blDataType> operator+ (const difference_type& movement){auto oldPtr = m_ptr;m_ptr+=movement;auto temp(*this);m_ptr = oldPtr;return temp;}
    blRawIterator<blDataType> operator- (const difference_type& movement){auto oldPtr = m_ptr;m_ptr-=movement;auto temp(*this);m_ptr = oldPtr;return temp;}

    difference_type operator-(const blRawIterator<blDataType>& rawIterator){return std::distance(rawIterator.getPtr(),this->getPtr());}

    blDataType& operator*(){return *m_ptr;}
    const blDataType& operator*()const{return *m_ptr;}
    blDataType* operator->(){return m_ptr;}

    blDataType* getPtr()const{return m_ptr;}
    const blDataType* getConstPtr()const{return m_ptr;}

protected:

    blDataType * m_ptr;
};
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Raw reverse iterator with random access
//-------------------------------------------------------------------
template<typename blDataType>
class blRawReverseIterator : public blRawIterator<blDataType>
{
public:

    blRawReverseIterator(blDataType* ptr = nullptr):blRawIterator<blDataType>(ptr){}
    blRawReverseIterator(const blRawIterator<blDataType>& rawIterator){this->m_ptr = rawIterator.getPtr();}
    blRawReverseIterator(const blRawReverseIterator<blDataType>& rawReverseIterator) = default;
    ~blRawReverseIterator(){}

    blRawReverseIterator<blDataType>& operator=(const blRawReverseIterator<blDataType>& rawReverseIterator) = default;
    blRawReverseIterator<blDataType>& operator=(const blRawIterator<blDataType>& rawIterator){this->m_ptr = rawIterator.getPtr();return (*this);}
    blRawReverseIterator<blDataType>& operator=(blDataType* ptr){this->setPtr(ptr);return (*this);}

    blRawReverseIterator<blDataType>& operator+=(const difference_type& movement){this->m_ptr -= movement;return (*this);}
    blRawReverseIterator<blDataType>& operator-=(const difference_type& movement){this->m_ptr += movement;return (*this);}
    blRawReverseIterator<blDataType>& operator++(){--this->m_ptr;return (*this);}
    blRawReverseIterator<blDataType>& operator--(){++this->m_ptr;return (*this);}
    blRawReverseIterator<blDataType> operator++(int){auto temp(*this);--this->m_ptr;return temp;}
    blRawReverseIterator<blDataType> operator--(int){auto temp(*this);++this->m_ptr;return temp;}
    blRawReverseIterator<blDataType> operator+(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr-=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}
    blRawReverseIterator<blDataType> operator-(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr+=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}

    difference_type operator-(const blRawReverseIterator<blDataType>& rawReverseIterator){return std::distance(this->getPtr(),rawReverseIterator.getPtr());}

    blRawIterator<blDataType> base(){blRawIterator<blDataType> forwardIterator(this->m_ptr); ++forwardIterator; return forwardIterator;}
};
//-------------------------------------------------------------------

template<typename blDataType>
class blCustomContainer
{
public: // The typedefs

    typedef blRawIterator<blDataType>              iterator;
    typedef blRawIterator<const blDataType>        const_iterator;

    typedef blRawReverseIterator<blDataType>       reverse_iterator;
    typedef blRawReverseIterator<const blDataType> const_reverse_iterator;

                            .
                            .
                            .

public:  // The begin/end functions

    iterator begin(){return iterator(&m_data[0]);}
    iterator end(){return iterator(&m_data[m_size]);}

    const_iterator cbegin(){return const_iterator(&m_data[0]);}
    const_iterator cend(){return const_iterator(&m_data[m_size]);}

    reverse_iterator rbegin(){return reverse_iterator(&m_data[m_size - 1]);}
    reverse_iterator rend(){return reverse_iterator(&m_data[-1]);}

    const_reverse_iterator crbegin(){return const_reverse_iterator(&m_data[m_size - 1]);}
    const_reverse_iterator crend(){return const_reverse_iterator(&m_data[-1]);}

                            .
                            .
                            .
    // This is the pointer to the beginning of the data
    // This allows the container to either "view" data owned
    // by other containers or to own its own data
    // You would implement a "create" method for owning the data
    // and a "wrap" method for viewing data owned by other containers

    blDataType* m_data;
};