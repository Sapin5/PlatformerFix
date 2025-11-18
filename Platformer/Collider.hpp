#ifndef COLLIDER_H
#define COLLIDER_H
#include "raylib.h"
#include <string>
#include <vector>

class Collider {
private:
	bool enabled{ true };
	Vector2 position{ 100.0f, 100.0f };
	Vector2 scale{ 100.0f, 100.0f };
	//std::vector<std::string> canCollide;
	bool debug{ false };
	bool collided{ false };

public:
	Collider() = default;

	//, std::vector<std::string> canCollide
	Collider(Vector2 position, Vector2 scale, bool enabled, bool debug) {
		this->position = position;
		this->scale = scale;
		this->enabled = enabled;
		//this->canCollide = canCollide;
		this->debug = debug;
		
	}

	struct CollisionFlags {
		bool top{ false };
		bool bottom{ false };
		bool left{ false };
		bool right{ false };
	};

	CollisionFlags flags;


	/// <summary>
	/// Creates basic collider
	/// </summary>
	void createCollider();


	/// <summary>
	/// Toggle collider (Enable/Disable)
	/// </summary>
	/// <param name="enabled"></param>
	void enableCollider(bool enabled);


	/// <summary>
	/// Updates the colliders position
	/// </summary>
	/// <param name="newPosition"></param>
	void updatePosition(Vector2& newPosition);


	/// <summary>
	/// Populates collision flags.
	/// Half functionial
	/// </summary>
	/// <param name="intersections"></param>
	/// <param name="delta"></param>
	void populateFlags(Vector2 intersections, Vector2 delta);


	/// <summary>
	/// Performs AABB collsion test on colliders reference that is passed in
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool checkCollisions(Collider& other);


	/// <summary>
	///  Adjusts actors position to not clip through other collider
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	std::vector<float> adjustPostion(Collider& other);


	/// <summary>
	/// Returns collider position
	/// </summary>
	/// <returns></returns>
	Vector2 getPosition() const;

	/// <summary>
	/// Returns scale of collider
	/// </summary>
	/// <returns></returns>
	Vector2 getScale() const;
};

#endif // !COLLIDER_H
