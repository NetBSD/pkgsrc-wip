# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	sonnet-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://projects.kde.org/projects/frameworks/sonnet
COMMENT=	Spelling framework for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
