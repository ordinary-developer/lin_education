#ifndef POINTER_HPP
#define POINTER_HPP

template <typename T>
class Pointer {
    public:
        Pointer(T* inPtr);
        virtual ~Pointer();

        Pointer(const Pointer<T>& src) = delete;
        Pointer<T>& operator = (const Pointer<T>& rhs) = delete;

        //dereference operators
        T& operator * ();
        const T& operator * () const;
        
        T* operator -> ();
        const T* operator -> () const;

        operator void* () const { return mPtr; }
    private:
        T* mPtr;
};

template <typename T>
Pointer<T>::Pointer(T* inPtr) : mPtr(inPtr) { } 

template <typename T>
Pointer<T>::~Pointer() {
    delete mPtr;
    mPtr = nullptr;
}

template <typename T>
T& Pointer<T>::operator * () {
    return *mPtr;
}

template <typename T>
const T& Pointer<T>::operator * () const {
    return *mPtr;
}

template <typename T>
T* Pointer<T>::operator -> () {
    return mPtr;
}

template <typename T>
const T* Pointer<T>::operator -> () const {
    return mPtr;
}

#endif
