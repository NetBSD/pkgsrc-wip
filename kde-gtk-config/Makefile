# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kde-gtk-config-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Plasma5 GTK2 and GTK3 Configurator
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

CMAKE_ARGS+=	-DBUILDLINK_DIR=${BUILDLINK_DIR}

DEPENDS+=	kde-cli-tools>=${PLASMAVER}:../../wip/kde-cli-tools

USE_TOOLS+=	msgmerge pkg-config

CFLAGS+=	-I${BUILDLINK_PREFIX.harfbuzz}/include/harfbuzz

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
