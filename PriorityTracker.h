#ifndef Life
#define Life
#include<algorithm>
#include <map>
#include<vector>
#include<functional>
#include<utility>
using namespace std;
namespace Destroyer
{
	class LifetimeTracker
	{
		private:
			unsigned int longevity_;
			unsigned int priority_;
			
		public:
			LifetimeTracker(unsigned int x,unsigned int y) : longevity_(x) , priority_(y){}
			virtual ~LifetimeTracker() = 0;
			unsigned int getLongevity()
			{
				return longevity_;
			}
			unsigned int getPriority()
			{
				return priority_;
			}
		
	};
	// Definition required
	inline LifetimeTracker::~LifetimeTracker() {}
	
	
	
	
	
	// Concrete lifetime tracker for objects of type T
	class ConcreteLifetimeTracker : public LifetimeTracker
	{
		public:
			ConcreteLifetimeTracker(Resource* p,unsigned int longevity,unsigned int priority):LifetimeTracker(longevity,priority),pTracked_(p){}
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
	
	
	
	vector<int> priority_vector;
	std::map<int,vector<ConcreteLifetimeTracker*> > pTrackerArray;
	
	void AtExitFn()
	{
		for(std::vector<int>::iterator itp=priority_vector.begin();itp!=priority_vector.end();++itp){
			std::cout <<  "deleting priority "<< *itp << std::endl;
			for(std::vector<ConcreteLifetimeTracker*>::iterator it = pTrackerArray[*itp].begin(); it != pTrackerArray[*itp].end(); ++it)
			{
				std::cout <<  " longetivity is "<< (*it)->getLongevity() << std::endl;
				delete (*it);
			}
		}
	}
	
	void SetLongevity(Resource* pDynObject, unsigned int longevity,unsigned int priority)
	{
		ConcreteLifetimeTracker* p = new ConcreteLifetimeTracker(pDynObject, longevity,priority);
		map<int,vector<ConcreteLifetimeTracker*> >::iterator itr=pTrackerArray.find(priority);
		if(itr==pTrackerArray.end())
		{
			vector<ConcreteLifetimeTracker*> priority_level;
			priority_level.push_back(p);
			pTrackerArray.insert(pair<int,vector<ConcreteLifetimeTracker*>>(priority,priority_level));
			priority_vector.push_back(priority);
			std::sort(priority_vector.begin(),priority_vector.end(),greater<int>());
		}
		else
		{
			pTrackerArray.find(priority)->second.push_back(p);
		}
		std::stable_sort(pTrackerArray.find(priority)->second.begin(),pTrackerArray.find(priority)->second.end(),lesser_than_key);
	}
	
	
}

#endif
