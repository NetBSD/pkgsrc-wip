# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	frameworkintegration-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provide components to allow applications to integrate with a KDE Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf
DEPENDS+=	oxygen-fonts-[0-9]*:../../fonts/oxygen-fonts

USE_TOOLS+=	msgmerge pkg-config

.include "../../wip/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
