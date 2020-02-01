# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.lxqt
PKG_SUPPORTED_OPTIONS=	openbox pulseaudio openssh upower sudo
PKG_SUGGESTED_OPTIONS=	openbox

.include "../../mk/bsd.options.mk"

# \todo: When importing, add openbox to options file.
.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=	openbox>=3.6.1:../../wm/openbox
DEPENDS+=	obconf-qt>=0.14.1:../../wip/obconf-qt
DEPENDS+=	pulseaudio>=13.1:../../audio/pulseaudio
DEPENDS+=	pavucontrol-qt>=0.14.1:../../wip/pavucontrol-qt
DEPENDS+=	openssh>=8.0:../../security/openssh
DEPENDS+=	lxqt-openssh-askpass>=0.14.1:../../wip/lxqt-openssh-askpass
DEPENDS+=	upower>=0.99:../../sysutils/upower
DEPENDS+=	lxqt-powermanagement>=0.14.1:../../wip/lxqt-powermanagement
DEPENDS+=	sudo>=1.8:../../security/sudo
DEPENDS+=	lxqt-sudo>=0.14.1:../../wip/lxqt-sudo
.endif
