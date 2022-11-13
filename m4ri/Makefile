# $NetBSD$

DISTNAME=	m4ri-20200125
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/malb/m4ri/downloads/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/malb/m4ri
COMMENT=	Library for fast arithmetic with dense matrices over F2
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	m4ri.pc.in

CONFIGURE_ARGS+=	--disable-png
CONFIGURE_ARGS+=	--enable-openmp


.include "../../parallel/openmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
