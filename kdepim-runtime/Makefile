# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdepim-runtime-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Extends the functionality of kdepim
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/akonadi-calendar/buildlink3.mk"
.include "../../wip/akonadi-notes/buildlink3.mk"
.include "../../wip/kalarmcal/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kdav/buildlink3.mk"
.include "../../textproc/libkolabxml/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../wip/libkgapi/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
