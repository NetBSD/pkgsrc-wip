# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	akonadi-calendar-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Akonadi calendar integration
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
