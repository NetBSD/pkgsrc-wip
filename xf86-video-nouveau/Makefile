# $NetBSD: Makefile,v 1.2 2008/12/13 15:08:50 shattered Exp $
#

DISTNAME=	xf86-video-nouveau-0.0.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
COMMENT=	New (or nouveau) NVidia driver for modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
# XXX
CFLAGS+=	-I${BUILDLINK_PREFIX.glproto}/include

# or server in wip
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.3.1.0
.include "../../wip/libdrm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
