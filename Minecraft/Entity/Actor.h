#pragma once
#include "../Pos/AABB.h"

class Actor {
private:
	virtual bool __cdecl hasComponent(class HashedString const&);
	virtual void __cdecl filler_000();
	virtual void __cdecl reloadHardcodedClient(enum Actor_InitializationMethod, class VariantParameterList const&);
	virtual void __cdecl initializeComponents(Actor_InitializationMethod, VariantParameterList const&);
	virtual void __cdecl reloadComponents(Actor_InitializationMethod, VariantParameterList const&);
	virtual void __cdecl _serverInitItemStackIds();
	virtual void __cdecl _doInitialMove();
	virtual void __cdecl destructor(unsigned int);
	virtual void __cdecl reset();
	virtual int __cdecl getOnDeathExperience();
	virtual enum ActorType __cdecl getOwnerEntityType();
public:

	virtual void __cdecl remove();
	virtual void __cdecl setPos(Vec3 const&); // 12
	virtual void __cdecl filler_001();
	virtual enum PredictedMovementValues const& __cdecl getPredictedMovementValues();
	//virtual class StateVectorComponent const& __cdecl getStateVectorComponent();
	virtual Vec3 getPos();
};