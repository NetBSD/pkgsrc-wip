# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kholidays-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	KDE library for regional holiday information
LICENSE=	gnu-lgpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
