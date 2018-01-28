# $NetBSD: Makefile,v 1.1 2015/04/01 13:11:38 tnn2 Exp $

DISTNAME=	xf86-video-intel-0
CATEGORIES=	x11

GIT_REPOSITORIES=		xf86-video-intel
GIT_REPO.xf86-video-intel=	git://anongit.freedesktop.org/xorg/driver/xf86-video-intel
WRKSRC=				${WRKDIR}/${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--disable-dri3

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config automake autoconf autoreconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
