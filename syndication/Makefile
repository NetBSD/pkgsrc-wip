# $NetBSD: Makefile,v 1.43 2021/02/07 06:30:38 ryoon Exp $

DISTNAME=	syndication-${KF5VER}
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	RSS/Atom parser library
LICENSE=	gnu-lgpl-v2.1 AND 2-clause-bsd

.include "../../meta-pkgs/kde/kf5.mk"

#USE_TOOLS+=	flex bison

.include "../../textproc/kcodecs/buildlink3.mk"
#.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
