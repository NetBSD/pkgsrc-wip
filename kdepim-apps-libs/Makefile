# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdepim-apps-libs-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org
COMMENT=	KDE PIM application libraries
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../wip/libkleo/buildlink3.mk"
.include "../../wip/grantleetheme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
