# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kpackage-${KF5VER}
CATEGORIES=	archivers

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Installation and loading of additional content as packages
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcoreaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
