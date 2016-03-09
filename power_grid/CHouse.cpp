#include "CHouse.h"

CHouse::CHouse(CCity city) : m_City(&city) {
	m_City->IncreaseCount();
}

CHouse::~CHouse() {

}

std::string CHouse::GetCity(){
	return m_City->GetName();
}
int	CHouse::getCost(){
	return m_City->GetCost();
}

/* Junan: Serialization of houses is done in the CPlayer, i don't think it is necessary here

void CHouse::Serialize(pugi::xml_node &parent) {
	auto house = XMLAppendChild(parent, "house");
	XMLAppendAttribute(house, "city", m_City.GetName());
	XMLAppendAttribute(house, "player", m_Player.GetName());

}*/
/*
CPlayer* CHouse::BelongsTo() {
	return &m_Player;
}
*/
