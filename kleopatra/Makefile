# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kleopatra-${KAPPSVER}
CATEGORIES=	security

HOMEPAGE=	https://www.kde.org/applications/utilities/kleopatra/
COMMENT=	Certificate Manager and Unified Crypto GUI
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	paperkey>=1.3:../../security/paperkey

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../wip/libkleo/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
