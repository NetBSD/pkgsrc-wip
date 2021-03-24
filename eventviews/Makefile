# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	eventviews-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Library for creating events
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/calendarsupport/buildlink3.mk"
.include "../../wip/kdiagram/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
