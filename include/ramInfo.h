#ifndef _RAMINFO_H_
#define _RAMINFO_H_

#include <iostream>
#include <iomanip>

class ramInfo {
public:
	ramInfo(unsigned speed, unsigned cl);
	unsigned getSpeed() const;
	unsigned getCasLatency() const;
	double getTotalLatency() const;
	bool operator< (const ramInfo& info) const;
private:
	unsigned _speed;
	unsigned _casLatency;
	double _totalLatency;

	double calculateLatency(unsigned speed, unsigned cl) const;
};

std::ostream& operator<< (std::ostream& os, const ramInfo& info);

#endif