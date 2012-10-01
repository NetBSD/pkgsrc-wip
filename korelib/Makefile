# $NetBSD: Makefile,v 1.9 2012/10/01 21:57:40 asau Exp $

DISTNAME=	korelib-1.0
CATEGORIES=	devel kde
MASTER_SITES=	http://host33.ipowerweb.com/~smga3000/thekompany/Korelib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thekompany.com/projects/korelib/
COMMENT=	Cross-platform C++ library for developing modular applications

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_TOOLS+=	automake
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && automake -a --foreign -i
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
