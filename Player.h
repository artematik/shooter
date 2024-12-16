#pragma once
#include "Animator.h"
class Player
{
public:
	Player();
	// направления движения игрока
	enum class playermove {};
	// метод для появления игрока на игровом поле
	void spawn(sf::IntRect planet, sf::Vector2f resolution, int tileSize);
	void resetPlayerStats();
	bool getLive();
	bool hit(sf::Time timeHit);
	sf::Time getLastHitTime() const;
	// возвращает координаты игрока
	sf::FloatRect getPosition() const;
	// возвращает центральные коорлинаты игрока
	sf::Vector2f getCenter() const;
	float getRotation() const;
	sf::Sprite getSprite() const;
	// отрисовка игрока
	void draw(sf::RenderWindow& window) const;
	void move(playermove mov);
	void update(sf::Time deltaTime, sf::Vector2i mousePosition);
	void upgreadeHealth(float health);
	void increaseHeathLevel(float amount);
	float getHealth() const;
	float getMaxHealth() const;

private:
	const float HEALTH = 200;
	sf::Vector2f m_Position;
	sf::Sprite m_Sprite;
	Animator m_AnimPlayer = Animator(m_Sprite);
	// разрешение на анимирование игрока
	bool m_animMove = false;
	sf::Vector2f m_Resolution;
	sf::IntRect size_feeld;
	// размер текстур игрового поля
	int texture_size;
	// в каком направление движется игрок в данный момент
	playermove m_move;
	bool m_live;
	float m_Health;
	float m_MaxHealth;
	sf::Time m_LastHit;
	// частота перемещения игрока
	sf::Time m_time_moving;
	float m_Speed;

};

