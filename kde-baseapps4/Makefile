# $NetBSD: Makefile,v 1.35 2016/04/28 07:11:54 markd Exp $

DISTNAME=	kde-baseapps-16.04.0
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.04.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

CONFLICTS=	konq-plugins-[0-9]*

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_INTERPRETER+=	xdg-open
REPLACE.xdg-open.old=	.*/bin/env xdg-open
REPLACE.xdg-open.new=	${PREFIX}/bin/xdg-open
REPLACE_FILES.xdg-open=	lib/konq/Templates/Program.desktop

CHECK_INTERPRETER_SKIP=	share/kde/templates/.source/Program.desktop

CMAKE_CONFIGURE_ARGS+=	-DWITH_Baloo:BOOL=OFF

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../sysutils/libbaloo4/buildlink3.mk"
#.include "../../sysutils/baloo-widgets/buildlink3.mk"
#.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/libkactivities4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
#.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
