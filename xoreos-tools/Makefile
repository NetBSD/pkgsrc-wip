# $NetBSD$

DISTNAME=	xoreos-tools-0.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://xoreos.org/
COMMENT=	Tools to help the development of xoreos
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CXXFLAGS+=	-fpermissive

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
