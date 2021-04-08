# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	calendarsupport-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org
COMMENT=	Calendar support library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/akonadi-calendar/buildlink3.mk"
.include "../../wip/akonadi-notes/buildlink3.mk"
#.include "../../wip/kdepim-apps-libs/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
