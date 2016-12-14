# $NetBSD$

DISTNAME=	paxtest-0.9.15
CATEGORIES=	security
MASTER_SITES=	https://www.grsecurity.net/~spender/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pax.grsecurity.net/
COMMENT=	Test program for PaX functionality
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.OpenBSD
# These override the Makefile default settings, so compare when updating
MAKE_FLAGS+=	CFLAGS="-Wl,-R${PREFIX}/lib -fno-stack-protector -DRUNDIR=\\\"${PREFIX}/libexec/paxtest\\\""
MAKE_FLAGS+=	LDFLAGS="-R${PREFIX}/lib -lpthread"
MAKE_FLAGS+=	RUNDIR=${PREFIX}/libexec/paxtest

INSTALLATION_DIRS+=	bin lib libexec/paxtest

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/paxtest ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/shlibtest*.so ${DESTDIR}${PREFIX}/lib
	for i in anonmap execbss execdata execheap execstack mprotanon mprotbss mprotdata mprotheap mprotshbss mprotshdata mprotstack randamap randheap1 randmain1 randshlib randstack1 randstack2 rettofunc1 rettofunc1x rettofunc2 rettofunc2x shlibbss shlibdata writetext; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/libexec/paxtest; \
	done

.include "../../mk/bsd.pkg.mk"
