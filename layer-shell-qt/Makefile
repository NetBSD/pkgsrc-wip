# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	layer-shell-qt-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Qt component to allow applications to use the Wayland wl-layer-shell protocol
LICENSE=	gnu-lgpl-v3 AND cc0-1.0-universal AND mit AND modified-bsd

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
