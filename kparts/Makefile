# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kparts-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Document centric plugin system
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../wip/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
