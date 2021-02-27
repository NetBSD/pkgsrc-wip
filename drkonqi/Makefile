# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	drkonqi-${PLASMAVER}
CATEGORIES=	devel

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE crash handler
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

.include "../../devel/kidletime/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
