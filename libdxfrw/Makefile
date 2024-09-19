# $NetBSD$

GITHUB_PROJECT=	libdxfrw
DISTNAME=	libdxfrw-0.5.12
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=LibreCAD/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libdxfrw/
COMMENT=	C++ library to read/write DXF and to read DWG
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config automake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libdxfrw.pc.in

.include "../../mk/bsd.pkg.mk"
