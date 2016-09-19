# $NetBSD$

DISTNAME=	libixion-0.12.1
CATEGORIES=	math devel
MASTER_SITES=	http://kohei.us/files/ixion/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/ixion/ixion
COMMENT=	General purpose formula parser & interpreter
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CXXFLAGS+=	-std=c++11

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	CXXFLAGS=${CXXFLAGS:Q}

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
