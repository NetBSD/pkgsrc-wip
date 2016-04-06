# $NetBSD: Makefile,v 1.9 2015/05/30 01:49:33 krytarowski Exp $

.include "../../wip/liblxqt/Makefile.common"

DISTNAME=	lxqt-common-0.10.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Common data file required for running an lxde-qt session
LICENSE=	gnu-lgpl-v2.1

EGDIR=			share/examples/lxqt-common
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart	\
			${PKG_SYSCONFDIR}/lxqt 		\
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt

CONF_FILES+=	${EGDIR}/xdg/autostart/lxqt-compton.desktop			\
		${PKG_SYSCONFDIR}/autostart/lxqt-compton.desktop		\
		${EGDIR}/xdg/autostart/lxqt-desktop.desktop			\
		${PKG_SYSCONFDIR}/autostart/lxqt-desktop.desktop		\
		${EGDIR}/xdg/autostart/lxqt-globalkeyshortcuts.desktop		\
		${PKG_SYSCONFDIR}/autostart/lxqt-globalkeyshortcuts.desktop	\
		${EGDIR}/xdg/autostart/lxqt-notifications.desktop		\
		${PKG_SYSCONFDIR}/autostart/lxqt-notifications.desktop		\
		${EGDIR}/xdg/autostart/lxqt-panel.desktop			\
		${PKG_SYSCONFDIR}/autostart/lxqt-panel.desktop			\
		${EGDIR}/xdg/autostart/lxqt-policykit-agent.desktop		\
		${PKG_SYSCONFDIR}/autostart/lxqt-policykit-agent.desktop	\
		${EGDIR}/xdg/autostart/lxqt-powermanagement.desktop		\
		${PKG_SYSCONFDIR}/autostart/lxqt-powermanagement.desktop	\
		${EGDIR}/xdg/autostart/lxqt-qlipper-autostart.desktop		\
		${PKG_SYSCONFDIR}/autostart/lxqt-qlipper-autostart.desktop	\
		${EGDIR}/xdg/autostart/lxqt-runner.desktop			\
		${PKG_SYSCONFDIR}/autostart/lxqt-runner.desktop			\
		${EGDIR}/xdg/autostart/lxqt-xscreensaver-autostart.desktop	\
		${PKG_SYSCONFDIR}/autostart/lxqt-xscreensaver-autostart.desktop \
		${EGDIR}/xdg/lxqt/lxqt.conf					\
		${PKG_SYSCONFDIR}/lxqt/lxqt.conf				\
		${EGDIR}/xdg/lxqt/session.conf					\
		${PKG_SYSCONFDIR}/lxqt/session.conf				\
		${EGDIR}/xdg/lxqt/windowmanagers.conf				\
		${PKG_SYSCONFDIR}/lxqt/windowmanagers.conf			\
		${EGDIR}/xdg/menus/lxqt-applications.menu			\
		${PKG_SYSCONFDIR}/menus/lxqt-applications.menu			\
		${EGDIR}/xdg/pcmanfm-qt/lxqt/settings.conf			\
		${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt/settings.conf

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	autostart/CMakeLists.txt \
    			config/CMakeLists.txt	 \
			menu/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	post-patch

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
