#include "ramInfo.h"

ramInfo::ramInfo(unsigned speed, unsigned cl) {
	_speed = speed;
	_casLatency = cl;
	_totalLatency = calculateLatency(speed, cl);
}

unsigned ramInfo::getSpeed() const {
	return _speed;
}

unsigned ramInfo::getCasLatency() const {
	return _casLatency;
}

double ramInfo::getTotalLatency() const {
	return _totalLatency;
}

bool ramInfo::operator<(const ramInfo& info) const {
	return _totalLatency < info.getTotalLatency();
}

double ramInfo::calculateLatency(unsigned speed, unsigned cl) const {
	return (double)(2000 * cl) / speed;
}

std::ostream& operator<<(std::ostream& os, const ramInfo& info) {
	os << std::setw(4) << info.getSpeed() << "MT/s CL" << std::setw(2) << info.getCasLatency() << " : " << std::setw(5) << std::fixed << std::setprecision(2) << info.getTotalLatency() << "ns";
	return os;
}