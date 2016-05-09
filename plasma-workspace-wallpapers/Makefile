# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-workspace-wallpapers-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Additional wallpapers for the Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../wip/kde5/plasma.mk"

#USE_TOOLS+=	msgmerge pkg-config

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
