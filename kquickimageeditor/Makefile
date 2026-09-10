# $NetBSD: Makefile,v 1.24 2026/09/06 09:41:04 markd Exp $

DISTNAME=	kquickimageeditor-0.7.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=kquickimageeditor/}

HOMEPAGE=	https://invent.kde.org/libraries/kquickimageeditor
COMMENT=	QML image editing components
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_CXX_FEATURES+=	c++23

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../graphics/libhighway/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
