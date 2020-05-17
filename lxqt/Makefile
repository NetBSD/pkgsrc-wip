# $NetBSD$

PKGNAME=	lxqt-0.15.0
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Meta-package for the LXQt desktop environment

META_PACKAGE=	yes

.include "options.mk"

TOOL_DEPENDS+=	lxqt-build-tools>=0.7.0:../../wip/lxqt-build-tools

DEPENDS+=	libqtxdg>=3.5.0:../../wip/libqtxdg
DEPENDS+=	liblxqt>=0.15.0:../../wip/liblxqt
DEPENDS+=	libfm-qt>=0.15.1:../../wip/libfm-qt
DEPENDS+=	lxqt-themes>=0.15.0:../../wip/lxqt-themes
DEPENDS+=	pavucontrol-qt>=0.15.0:../../wip/pavucontrol-qt
DEPENDS+=	qtermwidget>=0.15.0:../../wip/qtermwidget
DEPENDS+=	lximage-qt>=0.15.0:../../wip/lximage-qt
DEPENDS+=	lxqt-about>=0.15.0:../../wip/lxqt-about
DEPENDS+=	lxqt-policykit>=0.15.0:../../wip/lxqt-policykit
DEPENDS+=	lxqt-admin>=0.15.0:../../wip/lxqt-admin
DEPENDS+=	lxqt-config>=0.15.0:../../wip/lxqt-config
DEPENDS+=	lxqt-globalkeys>=0.15.0:../../wip/lxqt-globalkeys
DEPENDS+=	lxqt-openssh-askpass>=0.15.0:../../wip/lxqt-openssh-askpass
DEPENDS+=	lxqt-notificationd>=0.15.0:../../wip/lxqt-notificationd
DEPENDS+=	lxqt-powermanagement>=0.15.0:../../wip/lxqt-powermanagement
DEPENDS+=	lxqt-qtplugin>=0.15.0:../../wip/lxqt-qtplugin
DEPENDS+=	lxqt-session>=0.15.0:../../wip/lxqt-session
DEPENDS+=	lxqt-sudo>=0.15.0:../../wip/lxqt-sudo
DEPENDS+=	pcmanfm-qt>=0.15.1:../../wip/pcmanfm-qt
DEPENDS+=	qterminal>=0.15.0:../../wip/qterminal
DEPENDS+=	lxqt-panel>=0.15.0:../../wip/lxqt-panel
DEPENDS+=	lxqt-runner>=0.15.0:../../wip/lxqt-runner
DEPENDS+=	screengrab>=2.0.1:../../wip/screengrab
DEPENDS+=	lxqt-archiver>=0.2.0:../../wip/lxqt-archiver
# The Oxygen icon set is the default that LXQt expects, and a compatible icon
# theme must be present for it to be fully usable. Breeze is another option.
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
# This pulls in quite a lot of dependencies, but, if translations are wanted,
# it's needed.
DEPENDS+=	qt5-qttranslations>=5.14.1:../../x11/qt5-qttranslations

.include "../../mk/bsd.pkg.mk"
