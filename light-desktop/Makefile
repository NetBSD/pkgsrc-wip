# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:34:45 jeremy-c-reed Exp $
#

DISTNAME=	light-desktop-0.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Fast and lightweight desktop

DEPENDS=	dejavu-ttf>2.28:../../fonts/dejavu-ttf
DEPENDS+=	foomatic-filters>=4.0.9:../../print/foomatic4-filters
DEPENDS+=	freefont-ttf>0:../../fonts/freefont-ttf
DEPENDS+=	ghostscript>=8.71:../../print/ghostscript
DEPENDS+=	gtk2-engines-murrine>=0:../../x11/gtk2-engines-murrine
##DEPENDS+=	gvfs>=1.2.3:../../sysutils/gvfs
#DEPENDS+=	hplip>=3:../../wip/hplip3
DEPENDS+=	leafpad>=0.8.17:../../editors/leafpad
DEPENDS+=	lxpanel>=0:../../wip/lxpanel
DEPENDS+=	openbox>0:../../wm/openbox
DEPENDS+=	pcmanfm>=0.5:../../sysutils/pcmanfm
DEPENDS+=	pnm2ppa>=1.12:../../print/pnm2ppa
DEPENDS+=	xdg-user-dirs>=0.10:../../x11/xdg-user-dirs
DEPENDS+=	xkeyboard-config>=0:../../x11/xkeyboard-config

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
DEPENDS+=	gnumeric>=1.10:../../math/gnumeric110
DEPENDS+=	gpicview>=0:../../graphics/gpicview
DEPENDS+=	gutenprint-lib>=0:../../print/gutenprint-lib
DEPENDS+=	liberation-ttf>=0:../../fonts/liberation-ttf
DEPENDS+=	lightdm>=0:../../new/lightdm
DEPENDS+=	lightdm-gtk-greeter>=0:../../new/lightdm-gtk-greeter
DEPENDS+=	lxappearance>=0:../../new/lxappearance
DEPENDS+=	lxlauncher>=0.2.2:../../new/lxlauncher
DEPENDS+=	lxsession>=0:../../new/lxsession
DEPENDS+=	lxsession-edit>=0:../../new/lxsession-edit
DEPENDS+=	lxshortcut>=0:../../new/lxshortcut
DEPENDS+=	lxrandr>=0.1:../../wip/lxrandr
DEPENDS+=	lxtask>=0.1:../../new/lxtask
DEPENDS+=	pidgin>=2.9:../../chat/pidgin
DEPENDS+=	xpad>=0:../../x11/xpad

####

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
