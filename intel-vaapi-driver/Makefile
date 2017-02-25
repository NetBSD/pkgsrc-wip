# $NetBSD$

DISTNAME=	intel-vaapi-driver-1.7.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=01org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/01org/intel-vaapi-driver/
COMMENT=	VA-API user mode driver for Intel GEN Graphics family
LICENSE=	mit

# TODO: Package seems to built fine but a way to properly install
# TODO: it should be implemented and multimedia/libva/available.mk
# TODO: should be checked to conditionally mark this package BROKEN
# TODO: on such platforms.
BROKEN=		Properly handle the installation and check for libva availability

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config

CONFIGURE_ARGS+=	--disable-wayland

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
