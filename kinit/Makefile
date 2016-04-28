# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kinit-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Process launcher to speed up launching KDE applications
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../wip/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
