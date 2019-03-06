# $NetBSD$

DISTNAME=	libm4ri_20140914.orig
PKGNAME=	libm4ri-20140914
CATEGORIES=	math
MASTER_SITES=	http://deb.debian.org/debian/pool/main/libm/libm4ri/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://m4ri.sagemath.org/
COMMENT=	Method of the Four Russians Inversion library, shared library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/m4ri-20140914
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	m4ri.pc.in

.include "../../mk/bsd.pkg.mk"
