// fielddecode.c was generated by ProtoGen version 2.12.c

#include "fielddecode.h"
#include "floatspecial.h"


/*!
 * Decode a null terminated string from a byte stream
 * \param string receives the deocded null-terminated string.
 * \param bytes is a pointer to the byte stream to be decoded.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by the number of bytes decoded when this function
 *        is complete.
 * \param maxLength is the maximum number of bytes that can be decoded.
 *        maxLength includes the null terminator, which is always applied.
 * \param fixedLength should be 1 to force the number of bytes decoded to be
 *        exactly equal to maxLength.
 */
void stringFromBytes(char* string, const uint8_t* bytes, int* index, int maxLength, int fixedLength)
{
    int i;

    // increment byte pointer for starting point
    bytes += *index;

    for(i = 0; i < maxLength - 1; i++)
    {
        if(bytes[i] == 0)
            break;
        else
            string[i] = (char)bytes[i];
    }

    // Make sure we include null terminator
    string[i++] = 0;

    if(fixedLength)
        (*index) += maxLength;
    else
        (*index) += i;

}// stringFromBytes


/*!
 * Copy an array of bytes from a byte stream without changing the order.
 * \param data receives the copied bytes
 * \param bytes is a pointer to the byte stream to be copied from.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesFromBeBytes(uint8_t* data, const uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // Copy the bytes without changing the order
    while(num > 0)
    {
        *(data++) = *(bytes++);
        num--;
    }

}// bytesFromBeBytes


/*!
 * Copy an array of bytes from a byte stream, reversing the order.
 * \param data receives the copied bytes
 * \param bytes is a pointer to the byte stream to be copied.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by num when this function is complete.
 * \param num is the number of bytes to copy
 */
void bytesFromLeBytes(uint8_t* data, const uint8_t* bytes, int* index, int num)
{
    // increment byte pointer for starting point
    bytes += (*index);

    // Increment byte index to indicate number of bytes copied
    (*index) += num;

    // To encode as "little endian bytes", (a nonsensical statement), reverse the byte order
    bytes += (num - 1);

    // Copy the bytes, reversing the order
    while(num > 0)
    {
        *(data++) = *(bytes--);
        num--;
    }

}// bytesFromLeBytes

#ifdef UINT64_MAX

/*!
 * Decode a unsigned 8 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint64FromBeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 8;

    return number;
}


/*!
 * Decode a unsigned 8 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint64FromLeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 7;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 8;

    return number;
}


/*!
 * Decode a signed 8 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int64FromBeBytes(const uint8_t* bytes, int* index)
{
    int64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 8;

    return number;
}


/*!
 * Decode a signed 8 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int64FromLeBytes(const uint8_t* bytes, int* index)
{
    int64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 7;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 8;

    return number;
}


/*!
 * Decode a unsigned 7 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 7 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint56FromBeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 7;

    return number;
}


/*!
 * Decode a unsigned 7 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 7 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint56FromLeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 6;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 7;

    return number;
}


/*!
 * Decode a signed 7 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 7 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int56FromBeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0080000000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 7;

    return (number ^ m) - m;
}


/*!
 * Decode a signed 7 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 7 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int56FromLeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0080000000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 6;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 7;

    return (number ^ m) - m;
}


/*!
 * Decode a unsigned 6 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 6 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint48FromBeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 6;

    return number;
}


/*!
 * Decode a unsigned 6 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 6 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint48FromLeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 5;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 6;

    return number;
}


/*!
 * Decode a signed 6 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 6 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int48FromBeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0000800000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 6;

    return (number ^ m) - m;
}


/*!
 * Decode a signed 6 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 6 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int48FromLeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0000800000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 5;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 6;

    return (number ^ m) - m;
}


/*!
 * Decode a unsigned 5 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 5 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint40FromBeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 5;

    return number;
}


/*!
 * Decode a unsigned 5 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 5 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint64_t uint40FromLeBytes(const uint8_t* bytes, int* index)
{
    uint64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 4;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 5;

    return number;
}


/*!
 * Decode a signed 5 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 5 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int40FromBeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0000008000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 5;

    return (number ^ m) - m;
}


/*!
 * Decode a signed 5 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 5 when this function is complete.
 * \return the number decoded from the byte stream
 */
int64_t int40FromLeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int64_t m = 0x0000008000000000LL;
    int64_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 4;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 5;

    return (number ^ m) - m;
}

#endif // UINT64_MAX

/*!
 * Decode a 4 byte float from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
float float32FromBeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.integerValue = uint32FromBeBytes(bytes, index);

    if(isFloat32Valid(field.integerValue))
        return field.floatValue;
    else
        return 0;
}


/*!
 * Decode a 4 byte float from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
float float32FromLeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        float floatValue;
        uint32_t integerValue;
    }field;

    field.integerValue = uint32FromLeBytes(bytes, index);

    if(isFloat32Valid(field.integerValue))
        return field.floatValue;
    else
        return 0;
}


/*!
 * Decode a unsigned 4 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint32FromBeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}


/*!
 * Decode a unsigned 4 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint32FromLeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 3;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}


/*!
 * Decode a signed 4 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int32FromBeBytes(const uint8_t* bytes, int* index)
{
    int32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}


/*!
 * Decode a signed 4 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 4 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int32FromLeBytes(const uint8_t* bytes, int* index)
{
    int32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 3;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 4;

    return number;
}


/*!
 * Decode a unsigned 3 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint24FromBeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return number;
}


/*!
 * Decode a unsigned 3 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint32_t uint24FromLeBytes(const uint8_t* bytes, int* index)
{
    uint32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 2;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return number;
}


/*!
 * Decode a signed 3 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int24FromBeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int32_t m = 0x00800000;
    int32_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return (number ^ m) - m;
}


/*!
 * Decode a signed 3 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \return the number decoded from the byte stream
 */
int32_t int24FromLeBytes(const uint8_t* bytes, int* index)
{
    // Signed value in non-native size, requires sign extension. Algorithm
    // courtesty of: https://graphics.stanford.edu/~seander/bithacks.html
    const int32_t m = 0x00800000;
    int32_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 2;

    number = *(bytes--);
    number = (number << 8) | *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 3;

    return (number ^ m) - m;
}


/*!
 * Decode a unsigned 2 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint16_t uint16FromBeBytes(const uint8_t* bytes, int* index)
{
    uint16_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}


/*!
 * Decode a unsigned 2 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint16_t uint16FromLeBytes(const uint8_t* bytes, int* index)
{
    uint16_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 1;

    number = *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}


/*!
 * Decode a signed 2 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
int16_t int16FromBeBytes(const uint8_t* bytes, int* index)
{
    int16_t number;

    // increment byte pointer for starting point
    bytes += *index;

    number = *(bytes++);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}


/*!
 * Decode a signed 2 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \return the number decoded from the byte stream
 */
int16_t int16FromLeBytes(const uint8_t* bytes, int* index)
{
    int16_t number;

    // increment byte pointer for starting point
    bytes += (*index) + 1;

    number = *(bytes--);
    number = (number << 8) | *bytes;

    (*index) += 2;

    return number;
}


/*!
 * Decode a unsigned 1 byte integer from a byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 * \return the number decoded from the byte stream
 */
uint8_t uint8FromBytes(const uint8_t* bytes, int* index)
{
    return (uint8_t)bytes[(*index)++];
}


/*!
 * Decode a signed 1 byte integer from a byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 1 when this function is complete.
 * \return the number decoded from the byte stream
 */
int8_t int8FromBytes(const uint8_t* bytes, int* index)
{
    return (int8_t)bytes[(*index)++];
}


/*!
 * Decode a 8 byte float from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
double float64FromBeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        double floatValue;
        uint64_t integerValue;
    }field;

    field.integerValue = uint64FromBeBytes(bytes, index);

    if(isFloat64Valid(field.integerValue))
        return field.floatValue;
    else
        return 0;
}


/*!
 * Decode a 8 byte float from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 8 when this function is complete.
 * \return the number decoded from the byte stream
 */
double float64FromLeBytes(const uint8_t* bytes, int* index)
{
    union
    {
        double floatValue;
        uint64_t integerValue;
    }field;

    field.integerValue = uint64FromLeBytes(bytes, index);

    if(isFloat64Valid(field.integerValue))
        return field.floatValue;
    else
        return 0;
}


/*!
 * Decode a signed 3 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param sigbits is the number of bits to use in the significand of the float.
 * \return the number decoded from the byte stream
 */
float float24FromBeBytes(const uint8_t* bytes, int* index, int sigbits)
{
    return float24ToFloat32ex(uint24FromBeBytes(bytes, index), sigbits);
}


/*!
 * Decode a signed 3 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 3 when this function is complete.
 * \param sigbits is the number of bits to use in the significand of the float.
 * \return the number decoded from the byte stream
 */
float float24FromLeBytes(const uint8_t* bytes, int* index, int sigbits)
{
    return float24ToFloat32ex(uint24FromLeBytes(bytes, index), sigbits);
}


/*!
 * Decode a signed 2 byte integer from a big endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param sigbits is the number of bits to use in the significand of the float.
 * \return the number decoded from the byte stream
 */
float float16FromBeBytes(const uint8_t* bytes, int* index, int sigbits)
{
    return float16ToFloat32ex(uint16FromBeBytes(bytes, index), sigbits);
}


/*!
 * Decode a signed 2 byte integer from a little endian byte stream.
 * \param bytes is a pointer to the byte stream which contains the encoded data.
 * \param index gives the location of the first byte in the byte stream, and
 *        will be incremented by 2 when this function is complete.
 * \param sigbits is the number of bits to use in the significand of the float.
 * \return the number decoded from the byte stream
 */
float float16FromLeBytes(const uint8_t* bytes, int* index, int sigbits)
{
    return float16ToFloat32ex(uint16FromLeBytes(bytes, index), sigbits);
}


// end of fielddecode.c
