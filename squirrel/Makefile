# $NetBSD$

PKGNAME=	squirrel-${VERSION}
DISTNAME=	squirrel_${VERSION:S/./_/g}_stable
VERSION=	3.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrel/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://squirrel-lang.org/
COMMENT=	The Squirrel programming language
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/squirrel3
NO_CONFIGURE=	yes
BUILD_TARGET=	sq32

# XXX something like this would be nice
#.if !empty(${MACHINE_ARCH:M*64*})
#BUILD_TARGET=	sq64
#.else
#BUILD_TARGET=	sq32
#.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sq ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
.include "../../mk/fetch/sites.mk"
