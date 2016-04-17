#ifndef ibstring_h__INCLUDED
#define ibstring_h__INCLUDED

#ifdef IB_USE_STD_STRING
#include <string>
typedef std::string IBString;
#else
#include <afxstr.h>
typedef CString IBString;
#endif

inline bool IsEmpty(const IBString& str)
{
#ifdef IB_USE_STD_STRING
	return str.empty();
#else
	return str.IsEmpty();
#endif
};

inline void Empty(IBString& str)
{
#ifdef IB_USE_STD_STRING
	str.erase();
#else
	str.Empty();
#endif
};

inline bool Compare(IBString str, const char* strToCompare)
{
#ifdef IB_USE_STD_STRING
	// warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)
	//return str.compare(strToCompare);
	return str.compare(strToCompare) != 0;
#else
	return str.CompareNoCase(strToCompare);
#endif
};

inline bool Compare(IBString str, IBString strToCompare)
{
#ifdef IB_USE_STD_STRING
	// warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)
	//return str.compare(strToCompare);
	return str.compare(strToCompare) != 0;
#else
	return str.CompareNoCase(strToCompare);
#endif
};

inline double Atof(IBString str)
{
#ifdef IB_USE_STD_STRING
	return atof(str.c_str());
#else
	return atof(str);
#endif
};

inline int Atoi(IBString str)
{
#ifdef IB_USE_STD_STRING
	return atoi(str.c_str());
#else
	return atoi(str);
#endif
};

#endif


