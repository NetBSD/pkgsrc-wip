# $NetBSD$

.include "../../wip/smallbasic/Makefile.common"

PKGNAME=	${DISTNAME:tl:S/smallbasic/smallbasic-gui/}
CATEGORIES+=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SmallBASIC with GUI

CONFIGURE_ARGS+=	--enable-sdl

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
