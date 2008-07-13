# $NetBSD: Makefile,v 1.6 2008/07/13 12:06:43 tnn2 Exp $

DISTNAME=	xf86-video-ati-6.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular Xorg ATI video driver

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-dri

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

###
### XXX there must be a way to do this properly ... just can't think of it
###
XSERVER_DEPENDS!=	pkg_info -QREQUIRES modular-xorg-server

.if !empty(XSERVER_DEPENDS:M*pixman*)
.include "../../wip/modular-xorg-server/buildlink3.mk"
.else
.include "../../x11/modular-xorg-server/buildlink3.mk"
.endif

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
