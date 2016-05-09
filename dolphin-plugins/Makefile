# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	dolphin-plugins-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	http://kde.org/applications/system/dolphin/
COMMENT=	Extra Dolphin plugins
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../wip/kdoctools

USE_TOOLS+=	msgmerge

.include "../../wip/dolphin5/buildlink3.mk"
.include "../../wip/kdelibs4support/buildlink3.mk"
.include "../../wip/ktexteditor/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
