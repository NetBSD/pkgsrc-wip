# $NetBSD$

DISTNAME=	libfixposix-0.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sionescu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sionescu/libfixposix/
COMMENT=	Thin wrapper over POSIX syscalls
LICENSE=	boost-license

USE_TOOLS+=	pkg-config autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_CC_FEATURES+=	c99
PKGCONFIG_OVERRIDE+=	src/libfixposix.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
