#include "Language.h"
#include "utils/StringUtil.h"
USING_NS_CC;
using namespace tinyxml2;
using namespace std;
using std::vector;
//�Ƿ��ʼ��
static bool isInit = false;
static CCDictionary* dict = NULL;
static XMLElement* rootElement;
static tinyxml2::XMLDocument* doc;
Language::Language(void)
{
}


Language::~Language(void)
{
}

void Language::init(string name)
{
	if(!isInit)
	{
		dict = CCDictionary::create();
		dict->retain();
		doc = new tinyxml2::XMLDocument();
		doc->LoadFile(name.c_str());
		rootElement = doc->RootElement();
		XMLElement *element = rootElement->FirstChildElement();
		while (element)
		{
			CCString* node = ccs(element->GetText());
			dict->setObject(node, string (element->Name()));
			element = element->NextSiblingElement();
		}
		isInit = true;
	}
}

const char* Language::get( string name, vector<string> *v/*=NULL*/ )
{
	CCString* translation = (CCString* )dict->objectForKey(name);
	if(v && v->size() > 0)
	{
		string newStr;
		vector<string> tranVector;
		StringUtil::split(tranVector, string(translation->getCString()), "####");
		unsigned int size = tranVector.size();
		unsigned int vsize = v->size();
		if(vsize > size) vsize = size;
		for (unsigned int i = 0; i < size; i++)
		{
			//���ָ���ַ�������ֵ�
			string str = tranVector[i];
			newStr += str;
			//������滻�ֵ䳤��С�ڵ�ǰ����
			if(i < vsize)
			{
				newStr += (*v)[i];
			}
		}
		translation = ccs(newStr);
		tranVector.clear();
	}
	return translation->getCString();
}
