# $NetBSD$

DISTNAME=	foot-1.16.2
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/foot/releases/download/${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://codeberg.org/dnkl/foot/
COMMENT=	Terminal for Wayland
LICENSE=	mit

USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/terminfo

.include "../../devel/meson/build.mk"
.include "../../converters/utf8proc/buildlink3.mk"
#.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/fcft/buildlink3.mk"
.include "../../wip/tllist/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
