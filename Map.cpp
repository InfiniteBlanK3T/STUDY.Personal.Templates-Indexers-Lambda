#include "Map.h"

template<typename Key, typename Value>
Map<Key, Value>::Map(const Key& aKey, const Value& aValue) noexcept :
	fKey(aKey),
	fValue(aValue)
{}

template<typename Key, typename Value>
const Key& Map<Key, Value>::key() const noexcept
{
	return fKey;
}

template<typename Key, typename Value>
const Value& Map<Key, Value>::value() const noexcept
{
	return fValue;
}
template<typename Key, typename Value>
template<typename U>
inline Map<Key, Value>::operator U() const noexcept
{
	return static_cast<U>(Value);
}
template<typename Key, typename Value>
std::istream& operator>>(std::istream& aIStream, Map<Key, Value>& aMap)
{
	return aIStream >> aMap.fKey >> aMap.fValue;
}
template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& aOStream, const Map<Key, Value>& aMap)
{
	return aOStream << aMap.fKey << aMap.fValue;
}

