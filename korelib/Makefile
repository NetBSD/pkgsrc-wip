# $NetBSD: Makefile,v 1.3 2004/08/17 18:27:57 tvierling Exp $

DISTNAME=	korelib-1.0
CATEGORIES=	devel kde
MASTER_SITES=	http://host33.ipowerweb.com/~smga3000/thekompany/Korelib/

MAINTAINER=	jnr@cwru.edu
HOMEPAGE=	http://www.thekompany.com/projects/korelib/
COMMENT=	Cross-platform C++ library for developing modular applications

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LIBTOOL_LA_FILES+=	lib/libkore.la
LIBTOOL_LA_FILES+=	lib/libkoretest.la
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	cd ${WRKSRC} ; \
	${ACLOCAL} ; \
	${AUTOHEADER} ; \
	${AUTOMAKE} -a --foreign -i ; \
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
