#ifndef _STRPLUSSTR_H_
#define _STRPLUSSTR_H_

class StrplusStr {
private:
	char* _ab;

public:
	char* _resp;

	StrplusStr();
	~StrplusStr();

	size_t tam(const char* ptr) const;

	char* plus(char*, char*);
	char* plus(const char*, const char*);

};//fim da classe

#endif