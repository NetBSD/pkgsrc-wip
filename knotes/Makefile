# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	knotes-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Popup notes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../wip/grantleetheme/buildlink3.mk"
.include "../../wip/kontactinterface/buildlink3.mk"
.include "../../wip/kdepim-runtime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
