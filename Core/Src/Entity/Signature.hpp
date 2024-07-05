#ifndef SIGNATURE_HPP
#define SIGNATURE_HPP

using Signature = unsigned long;


const unsigned long POSITION_SIGNATURE_MASK = 0x1;
const unsigned long VELOCITY_SIGNATURE_MASK = 0x2;
const unsigned long ACCELERATION_SIGNATURE_MASK = 0x4;
const unsigned long SCALE_SIGNATURE_MASK = 0x8;
const unsigned long ROTATION_SIGNATURE_MASK = 0x10;
const unsigned long BOUNDINGBOX_SIGNATURE_MASK = 0x20;
const unsigned long BOUNDINGSPHERE_SIGNATURE_MASK = 0x40;
const unsigned long SCRIPT_SIGNATURE_MASK = 0x80;
const unsigned long TEXTURE_SIGNATURE_MASK = 0x100;
const unsigned long COORDINATEREFERENCE_SIGNATURE_MASK = 0x200;

#endif // SIGNATURE_HPP