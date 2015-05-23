# $NetBSD: Makefile,v 1.6 2015/05/23 20:28:04 krytarowski Exp $

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

OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/lxqt
OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/pcmanfm-qt/lxqt

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

CONF_FILES+=	${EGDIR}/xdg/lxqt/lxqt.conf ${PKG_SYSCONFDIR}/xdg/lxqt/lxqt.conf
CONF_FILES+=	${EGDIR}/xdg/lxqt/session.conf ${PKG_SYSCONFDIR}/xdg/lxqt/session.conf
CONF_FILES+=	${EGDIR}/xdg/lxqt/windowmanagers.conf ${PKG_SYSCONFDIR}/xdg/lxqt/windowmanagers.conf
CONF_FILES+=	${EGDIR}/xdg/menus/lxqt-applications.menu ${PKG_SYSCONFDIR}/xdg/menus/lxqt-applications.menu
CONF_FILES+=	${EGDIR}/xdg/pcmanfm-qt/lxqt/settings.conf ${PKG_SYSCONFDIR}/xdg/pcmanfm-qt/lxqt/settings.conf

SUBST_CLASSES+=		xdg confdir
SUBST_FILES.xdg=	autostart/CMakeLists.txt
SUBST_SED.xdg=		-e 's,/etc/xdg/autostart,${EGDIR}/xdg/autostart,'
SUBST_STAGE.xdg=	post-patch

SUBST_FILES.confdir=	config/CMakeLists.txt menu/CMakeLists.txt
SUBST_SED.confdir=	-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.confdir=	post-patch

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
