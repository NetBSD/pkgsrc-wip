# $NetBSD$

DISTNAME=	angelscript_2.36.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	lang
MASTER_SITES=	http://angelcode.com/angelscript/sdk/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://angelcode.com/angelscript/
COMMENT=	The AngelScript programming language
LICENSE=	zlib

WRKSRC=		${WRKDIR}/sdk/angelscript/projects/cmake
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
