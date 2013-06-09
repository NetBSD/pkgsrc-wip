# $NetBSD: Makefile,v 1.5 2013/06/09 12:48:36 othyro Exp $

DISTNAME=	xf86-video-nv-2.1.16
CATEGORIES=	x11

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg NVIDIA video driver

LICENSE=	mit

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://cgit.freedesktop.org/xorg/driver/xf86-video-nv
.include "../../wip/mk/git-package.mk"

BUILD_DEPENDS+=		xorg-util-macros-[0-9]*:../../devel/xorg-util-macros

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config autoconf autoreconf automake

WRKSRC=		${WRKDIR}/xf86-video-nv

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -v --install

.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
