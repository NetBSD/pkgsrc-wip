# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libksieve-${KAPPSVER}
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library for managing sieves
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
