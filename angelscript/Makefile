# $NetBSD$

PKGNAME=	angelscript-${VERSION}
DISTNAME=	angelscript_${VERSION}
VERSION=	2.32.0
CATEGORIES=	lang
MASTER_SITES=	http://angelcode.com/angelscript/sdk/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://angelcode.com/angelscript/
COMMENT=	The AngelScript programming language
LICENSE=	zlib

WRKSRC=		${WRKDIR}/sdk
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
AUTO_MKDIRS=	yes

REAL_SOURCE_DIR=	${WRKSRC}/angelscript/projects/gnuc
BUILD_DIRS+=		${REAL_SOURCE_DIR}
INSTALL_DIRS+=		${REAL_SOURCE_DIR}

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	DESTDIR=${DESTDIR}
INSTALL_TARGET=		install install_shared

.include "../../mk/bsd.pkg.mk"
