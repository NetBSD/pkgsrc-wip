# $NetBSD: Makefile.inc,v 1.1 2008/01/25 20:25:09 cheusov Exp $

BINDIR?=	${PREFIX}/bin

WARNS=		4

.if !defined(LIBPBULK_ONLY)
CPPFLAGS+=	-I${.CURDIR}/../lib
DPADD+=		${.OBJDIR}/../lib/libpbulk.a
LDADD+=		-L${.OBJDIR}/../lib -lpbulk
.endif

LDADD+=		-lnbcompat

.if !defined(NO_LIBEVENT_NEEDED)
CPPFLAGS+=
.if !defined(LIBPBULK_ONLY)
LDADD+=		-levent
.endif
.endif
