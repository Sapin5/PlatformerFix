#ifndef ACTOR_H
#define ACTOR_H

#include "BaseClass.hpp"
#include "Collider.hpp"
#include <string>
#include <functional>
#include "AnimationHandler.hpp"

class Actor : public Base{
protected:
	int scaleX;
	int scaleY;
	std::string tag{ "  " };
	Collider collider;
	AnimationHandler* sprites = nullptr;
	bool blankSprite{ false };
	bool isGrounded{ false };

public:
	/// <summary>
	/// Trigger ScreenShake. Function passed from game manager to actor
	/// </summary>
	std::function<void(float, float)> onShake;


	/// <summary>
	/// Players Position on screen
	/// </summary>
	Vector2 position{};


	Actor() = default;


	/// <summary>
	/// Spawn Actor class
	/// </summary>
	/// <param name="enableGravity"></param>
	/// <param name="position"></param>
	/// <param name="scaleX"></param>
	/// <param name="scaleY"></param>
	/// <param name="tag"></param>
	/// <param name="collisionEnabaled"></param>
	/// <param name="debug"></param>
	Actor(bool enableGravity, Vector2 position, int scaleX, int scaleY,
		std::string tag, bool collisionEnabaled, bool debug) : Base(enableGravity) {
		this->position = position;
		this->scaleX = scaleX;
		this->scaleY = scaleY;
		this->tag = tag;
		this->collider = Collider(position, { (float)scaleX, (float)scaleY }, collisionEnabaled, debug);
	}


	/// <summary>
	/// Draw actor on screen
	/// </summary>
	virtual void drawActor();
	

	/// <summary>
	/// Set a sprite sheet to actor
	/// </summary>
	/// <param name="sprites"></param>
	void setAnimation(AnimationHandler* sprites);


	/// <summary>
	/// Return the actors tag
	/// </summary>
	/// <returns></returns>
	std::string getTag();


	/// <summary>
	/// Apply a force on the actor
	/// </summary>
	/// <param name="force"></param>
	void applyForce(Vector2 force);


	/// <summary>
	/// 
	/// </summary>
	void update();


	/// <summary>
	/// Perform a collsion check on nearby objects
	/// </summary>
	/// <param name="other"></param>
	void collisionCheck(Collider& other);


	/// <summary>
	/// Return the collider of this object
	/// </summary>
	/// <returns></returns>
	Collider& getCollider();


	/// <summary>
	/// Return actors position
	/// </summary>
	/// <returns></returns>
	Vector2 getPosition();


	/// <summary>
	/// Enable sprite to hide default square
	/// </summary>
	/// <param name="value"></param>
	void spriteEnabled(bool value);
};

#endif // !ACTOR_H
