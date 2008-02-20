# $NetBSD: Makefile,v 1.3 2008/02/20 17:58:06 bsadewitz Exp $

DISTNAME=	xf86-video-ati-6.8.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
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
###
### XXX "Hey, Xorg, leave our pack alone!"
###	( to the tune of "Another Brick in the Wall" by Pink Floyd)
###
### Please, oh please, override our compiler-provided
### structure alignment!  We are all blithering idiots!
### Plus, if it isn't __exactly__ like Linux, it's broken,
### right?
.if ${OPSYS} != "Linux" # XXX If I wanted to sink to their level, this
			#     would not be here.  Alas, I won't.
BUILDLINK_TRANSFORM+=	rm-optarg:-DFGL_LINUX
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
