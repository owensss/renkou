#ifndef OBJECTCOUNTER_H
#define OBJECTCOUNTER_H

template <class BeingCounted>
class Counted
{
public:
        class TooManyObjects{};
        static int objectCount(){ return numObjects;}

protected:
        Counted();
        Counted(const Counted& rhs);
        ~Counted(){--numObjects;}

private:
        static int numObjects;
        static const int maxObjects;
        void init();
};

template <class BeingCounted>
Counted<BeingCounted>::Counted()
{ init();}

template <class BeingCounted>
Counted<BeingCounted>::Counted(const Counted<BeingCounted>&)
{ init();}

template <class BeingCounted>
void Counted<BeingCounted>::init()
{
        if(numObjects >= maxObjects)
                throw TooManyObjects();
        ++numObjects;
}

template<class BeingCounted>
int Counted<BeingCounted>::numObjects;

#endif // OBJECTCOUNTER_H
