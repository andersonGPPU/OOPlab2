#ifndef CLASS2_H
#define CLASS2_H

class iC; //classe proxy

class P2 {
public:
	P2(int);
	~P2();

	void sval(int);
	int rval() const;

private:
	iC* ptr; //ponteiro da proxy
};

#endif
