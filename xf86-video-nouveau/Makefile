# $NetBSD: Makefile,v 1.7 2013/06/09 12:48:36 othyro Exp $
#

DISTNAME=	xf86-video-nouveau-0.0.10
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
COMMENT=	New (or nouveau) NVidia driver for modular X.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
# XXX
CFLAGS+=	-I${BUILDLINK_PREFIX.glproto}/include

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

# or server in wip
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
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
