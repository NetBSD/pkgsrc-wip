/*	$NetBSD: ealloc.h,v 1.1.1.1 2003/04/28 16:16:38 jeremy-c-reed Exp $	*/

void	*emalloc(size_t);
char	*estrdup(const char *);
void	*erealloc(void *, size_t);
void	*ecalloc(size_t, size_t);
