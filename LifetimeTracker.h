#ifndef Life
#define Life
#include<algorithm>
#include<vector>
using namespace std;
namespace Private
{
	class LifetimeTracker
	{
		private:
			unsigned int longevity_;
			
		public:
			LifetimeTracker(unsigned int x) : longevity_(x) {}
			virtual ~LifetimeTracker() = 0;
			unsigned int getLongevity()
			{
				return longevity_;
			}
		
	};
	// Definition required
	inline LifetimeTracker::~LifetimeTracker() {}
	
	
	
	
	
	// Concrete lifetime tracker for objects of type T
	class ConcreteLifetimeTracker : public LifetimeTracker
	{
		public:
			ConcreteLifetimeTracker(Resource* p,unsigned int longevity):LifetimeTracker(longevity),pTracked_(p){}
			void print_value()
			{
				std::cout << "addr value =  [" << pTracked_ << "]" << std::endl;
			}
			~ConcreteLifetimeTracker()
			{
				delete pTracked_;
			}
		private:
			Resource* pTracked_;
			
	};
	
	bool lesser_than_key( ConcreteLifetimeTracker* obj1, ConcreteLifetimeTracker* obj2)
	{
		if (obj1->getLongevity() != obj2->getLongevity()) return obj1->getLongevity() < obj2->getLongevity();
    		return true;
	}
	
	vector<ConcreteLifetimeTracker*> pTrackerArray;
	
	void AtExitFn()
	{
		for(std::vector<ConcreteLifetimeTracker*>::iterator it = pTrackerArray.begin(); it != pTrackerArray.end(); ++it)
		{
			delete (*it);
		}
	}
	
	void SetLongevity(Resource* pDynObject, unsigned int longevity)
	{
		ConcreteLifetimeTracker* p = new ConcreteLifetimeTracker(pDynObject, longevity);
		pTrackerArray.push_back(p);
		std::stable_sort(pTrackerArray.begin(),pTrackerArray.end(),lesser_than_key);
	}
	
	
}

#endif
