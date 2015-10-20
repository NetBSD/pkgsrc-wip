# $NetBSD$

DISTNAME=	assimp-${VERSION}
VERSION=	3.1.1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=assimp/}
EXTRACT_SUFX=	.zip

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://assimp.sourceforge.net/
COMMENT=	Library to import various 3D model formats
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	assimp.pc.in
PKGCONFIG_OVERRIDE+=	contrib/cppunit-1.12.1/cppunit.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
