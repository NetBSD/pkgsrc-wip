# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	knotifications-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction for system notifications
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

.include "../../wip/kf5/Makefile.common"

.include "../../wip/kcodecs/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcoreaddons/buildlink3.mk"
.include "../../wip/kwindowsystem/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
