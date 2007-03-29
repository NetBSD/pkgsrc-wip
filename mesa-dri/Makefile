# $NetBSD: Makefile,v 1.2 2007/03/29 09:24:56 dillo Exp $
#

DISTNAME=	MesaLib-${MESA_VER}
PKGNAME=	mesa-dri-${MESA_VER}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mesa3d/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mesa3d.sourceforge.net/
COMMENT=	Mesa DRI drivers

MESA_VER=	6.5.2

WRKSRC=		${WRKDIR}/Mesa-${MESA_VER}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makedepend pkg-config
NO_CONFIGURE=	yes

post-extract:
	${CP} ${FILESDIR}/netbsd-dri* ${WRKSRC}/configs

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=	netbsd-dri
.  elif ${MACHINE_ARCH} == "i386"
BUILD_TARGET=	netbsd-dri
.  else
BUILD_TARGET=	netbsd-dri
.  endif
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
