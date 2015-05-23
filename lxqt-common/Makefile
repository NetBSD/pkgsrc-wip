# $NetBSD: Makefile,v 1.4 2015/05/23 18:23:45 krytarowski Exp $

DISTNAME=	lxqt-common-0.9.1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Common data file required for running an lxde-qt session
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/examples/lxqt-common

CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-compton.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-compton.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-desktop.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-desktop.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-globalkeyshortcuts.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-globalkeyshortcuts.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-notifications.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-notifications.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-panel.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-panel.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-policykit-agent.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-policykit-agent.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-powermanagement.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-powermanagement.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-ptbatterysystemtray-autostart.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-ptbatterysystemtray-autostart.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-qlipper-autostart.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-qlipper-autostart.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-qxkb-autostart.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-qxkb-autostart.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-runner.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-runner.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-screenlocker.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-screenlocker.desktop
CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-xscreensaver-autostart.desktop ${PKG_SYSCONFDIR}/xdg/autostart/lxqt-xscreensaver-autostart.desktop

CMAKE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PKG_SYSCONFDIR}/xdg

SUBST_CLASSES+=	xdg
SUBST_FILES.xdg=	autostart/CMakeLists.txt
SUBST_SED.xdg=		-e 's,/etc/xdg/autostart,${EGDIR}/xdg/autostart,'
SUBST_STAGE.xdg=	post-patch

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
