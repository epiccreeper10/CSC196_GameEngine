#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"
 namespace neu
 { 
	 class Scene;
	 class Actor : public GameObject
	 {
	 public:
		 Actor() = default;
		 Actor(const Model& model, const Transform& transform) : m_model{ model }, GameObject {transform} {}

		 virtual void Update() override {}
		 virtual void Draw(Renderer& renderer);

		 virtual void OnCollision(Actor* other) {}

		 std::string& GetTag() { return m_tag; }

		 float GetRadius() { return m_model.GetRadius() * (m_transform.scale - .5); }
	 public:
		 Scene* scene;
		 bool m_destory = false;
	 protected:
		 std::string m_tag;
		 
		 float m_damping = 1;
		 Vector2 m_velocity;
		 Model m_model;
		 
	 };
 }