#include <iostream>
using namespace std;

class CObj
{
	private:
		CObj() { cout << "Instance a object" << endl; }
		
	public:
		virtual ~CObj() {cout << "CObj::~CObj" << endl;   if(! s_pObj) delete s_pObj;  s_pObj = 0; }

		static CObj* Instance() 
		{
			//double lock
			if(0 == s_pObj)
			{
				//thread synchronization begin
				if(0 == s_pObj)
				{
					s_pObj = new CObj();
				}
				//thread synchronizatioin end
			}
			
			return s_pObj;
		}

		void Show() { cout << "CObj::Show()" << endl; }
	protected:
		static CObj* s_pObj;
};

CObj* CObj::s_pObj = 0;


int main()
{
	CObj* pObj = CObj::Instance();
	pObj->Show();
	delete pObj;
	pObj = 0;

	return 0;
}
