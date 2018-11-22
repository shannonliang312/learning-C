#include <stdio.h>

static const size_t BASE64_INPUT = 4;
static const size_t BASE64_OUTPUT = 3;
static const size_t BASE64_MAX_PADDING = 2;
static const unsigned char BASE64_MAX_VALUE = 63;
static const unsigned char BASE64_TABLE[ 0x80 ] = {
    /*00-07*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /*08-0f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /*10-17*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /*18-1f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /*20-27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    /*28-2f*/ 0xFF, 0xFF, 0xFF, 0x3e, 0xFF, 0xFF, 0xFF, 0x3f, /*2 = '+' and '/'*/
    /*30-37*/ 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, /*8 = '0'-'7'*/
    /*38-3f*/ 0x3c, 0x3d, 0xFF, 0xFF, 0xFF, 0x40, 0xFF, 0xFF, /*2 = '8'-'9' and '='*/
    /*40-47*/ 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, /*7 = 'A'-'G'*/
    /*48-4f*/ 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, /*8 = 'H'-'O'*/
    /*50-57*/ 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, /*8 = 'P'-'W'*/
    /*58-5f*/ 0x17, 0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /*3 = 'X'-'Z'*/
    /*60-67*/ 0xFF, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, /*7 = 'a'-'g'*/
    /*68-6f*/ 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, /*8 = 'h'-'o'*/
    /*70-77*/ 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, /*8 = 'p'-'w'*/
    /*78-7f*/ 0x31, 0x32, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  /*3 = 'x'-'z'*/
};

size_t cyoBase64Decode( void* dest, const char* src, size_t size )
{
    /*
     * output 3 bytes for every 4 input:
     *
     *               outputs: 1        2        3
     * inputs: 1 = --111111 = 111111--
     *         2 = --22XXXX = ------22 XXXX----
     *         3 = --3333XX =          ----3333 XX------
     *         4 = --444444 =                   --444444
     */

    if (dest && src && (size % BASE64_INPUT == 0))
    {
        unsigned char* pDest = (unsigned char*)dest;
        size_t dwSrcSize = size;
        size_t dwDestSize = 0;
        unsigned char in1, in2, in3, in4;

        while (dwSrcSize >= 1)
        {
            /* 4 inputs */
            in1 = *src++;
            in2 = *src++;
            in3 = *src++;
            in4 = *src++;
            dwSrcSize -= BASE64_INPUT;

            /* Validate ascii */
            if (in1 >= 0x80 || in2 >= 0x80 || in3 >= 0x80 || in4 >= 0x80)
                return 0; /*ERROR - invalid base64 character*/

            /* Convert ascii to base64 */
            in1 = BASE64_TABLE[ in1 ];
            in2 = BASE64_TABLE[ in2 ];
            in3 = BASE64_TABLE[ in3 ];
            in4 = BASE64_TABLE[ in4 ];

            /* Validate base64 */
            if (in1 > BASE64_MAX_VALUE || in2 > BASE64_MAX_VALUE)
                return 0; /*ERROR - invalid base64 character*/
            /*the following can be padding*/
            if (in3 > BASE64_MAX_VALUE + 1 || in4 > BASE64_MAX_VALUE + 1)
                return 0; /*ERROR - invalid base64 character*/

            /* 3 outputs */
            *pDest++ = ((in1 & 0x3f) << 2) | ((in2 & 0x30) >> 4);
            *pDest++ = ((in2 & 0x0f) << 4) | ((in3 & 0x3c) >> 2);
            *pDest++ = ((in3 & 0x03) << 6) | (in4 & 0x3f);
            dwDestSize += BASE64_OUTPUT;

            /* Padding */
            if (in4 == BASE64_MAX_VALUE + 1)
            {
                --dwDestSize;
                if (in3 == BASE64_MAX_VALUE + 1)
                {
                    --dwDestSize;
                }
            }
        }
        *pDest++ = '\x0'; /*append terminator*/

        return dwDestSize;
    }
    else
        return 0; /*ERROR - null pointer, or size isn't a multiple of 4*/
}

int main(int argc, char const *argv[])
{
  char decode_input[20] = "bGlhbmdzaGVuZ25hbg==";
  char decode_output[64] = {0};
  int destSize = 0;
  char *dest = NULL;

  destSize = cyoBase64Decode(decode_output, decode_input, 20);

  dest = (char *)malloc(destSize);
  snprintf(dest, destSize + 1, decode_output);

  // printf("destSize = %d\ndest = %s\ndest_size = %d\n", destSize, decode_output, sizeof(decode_output));
  printf("dest = %s\n", decode_output);
  printf("dest_size = %d\n", destSize);
  return 0;
}
