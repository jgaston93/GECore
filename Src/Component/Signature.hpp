#ifndef SIGNATURE_HPP
#define SIGNATURE_HPP

using Signature = unsigned long;

using ComponentIndex = unsigned long;

const ComponentIndex MAX_COMPONENT_INDEX = sizeof(Signature) * 8;

const ComponentIndex PositionIndex = 0;
const ComponentIndex VelocityIndex = 1;
const ComponentIndex AccelerationIndex = 2;
const ComponentIndex ScaleIndex = 3;
const ComponentIndex RotationIndex = 4;
const ComponentIndex BoundingBoxIndex = 5;
const ComponentIndex BoundingSphereIndex = 6;

#endif // SIGNATURE_HPP