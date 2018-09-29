#ifndef __MENTOS_STRINGUTILS_H
#define __MENTOS_STRINGUTILS_H

/* strlen:
 * Returns the length of the given string
 *
 * @param str	the string
 */
inline size_t strlen(const char *str)
{
	size_t len = 0;
	while(str[len]) len++;
	return len;
}

#endif
