# $NetBSD$

PKGNAME=	squirrel-${VERSION}
DISTNAME=	squirrel_${VERSION_ALT}_stable
VERSION=	3.0.7
VERSION_ALT=	3_0_7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrel/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://squirrel-lang.org/
COMMENT=	The Squirrel programming language
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/SQUIRREL3
NO_CONFIGURE=	yes
BUILD_TARGET=	sq64

do-install:
	( \
		cd ${WRKSRC}; \
		cp -v ./bin/sq ${DESTDIR}${PREFIX}/bin; \
	)

.include "../../mk/bsd.pkg.mk"
.include "../../mk/fetch/sites.mk"
