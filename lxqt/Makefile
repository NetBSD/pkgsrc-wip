# $NetBSD: Makefile,v 1.8 2015/05/23 16:07:35 krytarowski Exp $

PKGNAME=        lxqt-0.9.0
CATEGORIES=     meta-pkgs

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       https://lxqt.org/
COMMENT=        Meta-package for LXQt desktop environment

META_PACKAGE=   yes


# See https://wiki.lxde.org/en/Build_LXDE-Qt_From_Source
# example meta package from Mageia
# https://svnweb.mageia.org/packages/cauldron/task-lxqt/current/SPECS/task-lxqt.spec?view=markup

# Set of packages from https://downloads.lxqt.org/lxqt/0.9.0/
DEPENDS+=       liblxqt>=0.9.0:../../wip/liblxqt
DEPENDS+=       lximage-qt>=0.4.0:../../wip/lximage-qt
DEPENDS+=       lxmenu-data>=0.1.4:../../sysutils/lxmenu-data
DEPENDS+=       lxqt-about>=0.9.0:../../wip/lxqt-about
DEPENDS+=       lxqt-admin>=0.9.0:../../wip/lxqt-admin
DEPENDS+=       lxqt-common>=0.9.1:../../wip/lxqt-common
DEPENDS+=       lxqt-config>=0.9.0:../../wip/lxqt-config
DEPENDS+=       lxqt-globalkeys>=0.9.0:../../wip/lxqt-globalkeys
DEPENDS+=       lxqt-notificationd>=0.9.0:../../wip/lxqt-notificationd
DEPENDS+=       lxqt-openssh-askpass>=0.9.0:../../wip/lxqt-openssh-askpass
DEPENDS+=       lxqt-panel>=0.9.0:../../wip/lxqt-panel
DEPENDS+=       lxqt-policykit>=0.9.0:../../wip/lxqt-policykit
DEPENDS+=       lxqt-powermanagement>=0.9.0:../../wip/lxqt-powermanagement
DEPENDS+=       lxqt-qtplugin>=0.9.0:../../wip/lxqt-qtplugin
DEPENDS+=       lxqt-runner>=0.9.0:../../wip/lxqt-runner
DEPENDS+=       lxqt-session>=0.9.0:../../wip/lxqt-session
DEPENDS+=       pcmanfm-qt>=0.9.0:../../wip/pcmanfm-qt

# actively used by apps -- are there alternatives?
DEPENDS+=       oxygen-icons>=0.9.0:../../graphics/oxygen-icons

# to be verified whether we want it, for now just shut the warnings up
DEPENDS+=       qt5-qttranslations>=5.4.0:../../x11/qt5-qttranslations

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
