# $NetBSD$

DISTNAME=	wlrctl-0.2.2
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~brocellous/wlrctl/archive/
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}
DIST_SUBDIR=	wlrctl

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~brocellous/wlrctl/
COMMENT=	Utility for miscellaneous wlroots extensions
LICENSE=	mit

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/wlrctl-v${PKGVERSION_NOREV}

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
