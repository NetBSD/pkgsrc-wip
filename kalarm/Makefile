# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kalarm-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Personal alarm scheduler
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge perl:run

SUBST_CLASSES+=         xdg
SUBST_STAGE.xdg=        pre-configure
SUBST_MESSAGE.xdg=      Install via examples dir.
SUBST_FILES.xdg=        src/CMakeLists.txt
SUBST_SED.xdg=          -e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/kalarm.autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/kalarm.autostart.desktop

REPLACE_PERL+=	src/kconf_update/*.pl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kalarmcal/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../wip/mailcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
