# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:16 marttikuparinen Exp $

DISTNAME=	korelib-1.0
CATEGORIES=	devel kde
MASTER_SITES=	http://host33.ipowerweb.com/~smga3000/thekompany/Korelib/

MAINTAINER=	jnr@cwru.edu
HOMEPAGE=	http://www.thekompany.com/projects/korelib/
COMMENT=	Cross-platform C++ library for developing modular applications

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	cd ${WRKSRC} ; \
	${ACLOCAL} ; \
	${AUTOHEADER} ; \
	${AUTOMAKE} -a --foreign -i ; \
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
