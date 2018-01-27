# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	drkonqi-${PLASMAVER}
CATEGORIES=	devel

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE crash handler
LICENSE=	gnu-lgpl-v2

.include "../../wip/kde5/plasma.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kidletime/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
