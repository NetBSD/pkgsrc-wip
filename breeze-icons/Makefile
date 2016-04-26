# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	breeze-icons-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../wip/kf5/Makefile.common"

BUILDLINK_DEPMETHOD.qt5-qtbase= build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
