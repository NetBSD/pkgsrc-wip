# $NetBSD: Makefile,v 1.9 2013/04/21 18:04:04 kristerw Exp $

DISTNAME=	light-desktop-0.0
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.netbsd.org/light-desktop/
COMMENT=	Fast and lightweight desktop

META_PACKAGE=	yes

DEPENDS=	dejavu-ttf>2.28:../../fonts/dejavu-ttf
DEPENDS+=	elementary-icon-theme>=0:../../x11/elementary-icon-theme
DEPENDS+=	foomatic-filters>=4.0.9:../../print/foomatic4-filters
DEPENDS+=	freefont-ttf>0:../../fonts/freefont-ttf
DEPENDS+=	ghostscript-agpl>=8.71:../../print/ghostscript-agpl
DEPENDS+=	gtk2-engines-murrine>=0:../../x11/gtk2-engines-murrine
##DEPENDS+=	gvfs>=1.2.3:../../sysutils/gvfs
#DEPENDS+=	hplip>=3:../../wip/hplip3
DEPENDS+=	leafpad>=0.8.17:../../editors/leafpad
DEPENDS+=	lxde-common>=0.5:../../wip/lxde-common
DEPENDS+=	lxpanel>=0:../../wip/lxpanel
DEPENDS+=	lxterminal>=0:../../wip/lxterminal
DEPENDS+=	openbox>0:../../wm/openbox
DEPENDS+=	pcmanfm>=0.5:../../wip/pcmanfm
DEPENDS+=	pnm2ppa>=1.12:../../print/pnm2ppa
DEPENDS+=	xdg-user-dirs>=0.10:../../x11/xdg-user-dirs
DEPENDS+=	xkeyboard-config>=0:../../x11/xkeyboard-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	netbsd-light-desktop-artwork>=0:../../wip/netbsd-light-desktop-artwork
DEPENDS+=	netbsd-light-desktop-default-settings>=0:../../wip/netbsd-light-desktop-default-settings
.endif

# Suggestions

DEPENDS+=	abiword>=0:../../editors/abiword
DEPENDS+=	audacious>=1.5:../../audio/audacious
DEPENDS+=	audacious-plugins>=1.5:../../audio/audacious-plugins
DEPENDS+=	avahi>=0.6:../../net/avahi
DEPENDS+=	cups>=1.5:../../print/cups
# http://mail-index.netbsd.org/pkgsrc-bugs/2012/02/24/msg046701.html
#DEPENDS+=	obconf>=0:../../wm/obconf
DEPENDS+=	evince>=2.32:../../print/evince
DEPENDS+=	file-roller>=2.32:../../archivers/file-roller
DEPENDS+=	galculator>=1.3:../../math/galculator
DEPENDS+=	gnome-system-tools>=0:../../sysutils/gnome-system-tools
DEPENDS+=	gnumeric>=1.12:../../math/gnumeric112
DEPENDS+=	gpicview>=0:../../graphics/gpicview
DEPENDS+=	mtpaint>=0:../../wip/mtpaint
DEPENDS+=	gutenprint-lib>=0:../../print/gutenprint-lib
DEPENDS+=	liberation-ttf>=0:../../fonts/liberation-ttf
DEPENDS+=	lightdm>=0:../../wip/lightdm
DEPENDS+=	lightdm-gtk-greeter>=0:../../wip/lightdm-gtk-greeter
DEPENDS+=	lxappearance>=0:../../wip/lxappearance
DEPENDS+=	lxlauncher>=0.2.2:../../wip/lxlauncher
DEPENDS+=	lxsession>=0:../../x11/lxsession
DEPENDS+=	lxsession-edit>=0:../../wip/lxsession-edit
DEPENDS+=	lxshortcut>=0:../../wip/lxshortcut
DEPENDS+=	lxrandr>=0.1:../../wip/lxrandr
DEPENDS+=	lxtask>=0.1:../../wip/lxtask
DEPENDS+=	osmo>=0:../../wip/osmo
DEPENDS+=	scrot>=0:../../graphics/scrot
DEPENDS+=	pidgin>=2.9:../../chat/pidgin
DEPENDS+=	xpad>=0:../../x11/xpad

####

.include "../../mk/bsd.pkg.mk"
