# $NetBSD$

DISTNAME=	0.12.1
PKGNAME=	gumbo-parser-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/grisha/gumbo-parser/archive/
DIST_SUBDIR=	gumbo-parser

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/grisha/gumbo-parser/
COMMENT=	HTML5 parsing library in pure C99
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gumbo-parser

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake

PKGCONFIG_OVERRIDE=	gumbo.pc.in

USE_LANGUAGES=	c99 c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
