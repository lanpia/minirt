
// thank you jeekpark
unsigned char bitswap(unsigned char c) // 0000 1111 -> 1111 0000
{
	return (c >> 4) | (c << 4);
}