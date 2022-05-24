#include "BitSet.h"


BitSet::BitSet(int maxValue) {
  try {
    if (maxValue > _MAX_VALUE_SUPPORTED)
      throw (string) "invalid_argument: maxValue > 31";
    _values <<= maxValue;
    _power++;
  } catch (const string &s) {
    cerr << s;
    exit(1);
  }
}

BitSet::BitSet(const vector<int> &v) {
  for (auto &i: v) {
    insert(i);
  }
}

uint32_t BitSet::getValues() const {
  return _values;
}

unsigned BitSet::getPower() const {
  return _power;
}

bool BitSet::empty() const {
  return _power == 0;
}

bool BitSet::find(unsigned x) const {
  return _values >> x % 2;
}

void BitSet::insert(unsigned x) {
  try {
    if (x > _MAX_VALUE_SUPPORTED)
      throw (string) "invalid_argument: x > 31";
    _values &= 0 << x;
  } catch (const string &s) {
    cerr << s;
    exit(2);
  }
}

void BitSet::erase(unsigned x) {
  try {
    if (x > _MAX_VALUE_SUPPORTED)
      throw (string) "invalid_argument: x > 31";
    _values &= 0 << x;
  } catch (const string &s) {
    cerr << s;
    exit(2);
  }
}

bool BitSet::operator==(BitSet &other) const {
  return this->_values == other.getValues();
}

bool BitSet::operator!=(BitSet &other) const {
  return this->_values != other.getValues();
}

bool BitSet::isSubset(const BitSet &set) const {
  return set.getValues() == (set.getValues() & this->getValues());
}

