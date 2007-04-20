# $NetBSD: Makefile,v 1.2 2007/04/20 08:46:22 bsadewitz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-utils-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg utilities meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		xbiff-[0-9]*:../../mail/xbiff
DEPENDS+=		appres-[0-9]*:../../x11/appres
DEPENDS+=		beforelight-[0-9]*:../../x11/beforelight
DEPENDS+=		bitmap-[0-9]*:../../x11/bitmap
DEPENDS+=		ico-[0-9]*:../../x11/ico
DEPENDS+=		evieext-[0-9]*:../../x11/evieext
DEPENDS+=		editres-[0-9]*:../../x11/editres
DEPENDS+=		luit-[0-9]*:../../x11/luit
DEPENDS+=		rgb-[0-9]*:../../x11/rgb
DEPENDS+=		setxkbmap-[0-9]*:../../x11/setxkbmap
DEPENDS+=		xbitmaps-[0-9]*:../../x11/xbitmaps
DEPENDS+=		xinit-[0-9]*:../../x11/xinit
DEPENDS+=		xauth-[0-9]*:../../x11/xauth
DEPENDS+=		xmodmap-[0-9]*:../../x11/xmodmap
DEPENDS+=		xtrans-[0-9]*:../../x11/xtrans
DEPENDS+=		xrdb-[0-9]*:../../x11/xrdb
DEPENDS+=		xset-[0-9]*:../../x11/xset
DEPENDS+=		xsetroot-[0-9]*:../../x11/xsetroot
DEPENDS+=		xev-[0-9]*:../../x11/xev
DEPENDS+=		xwd-[0-9]*:../../x11/xwd
DEPENDS+=		xclock-[0-9]*:../../x11/xclock
DEPENDS+=		xconsole-[0-9]*:../../x11/xconsole
DEPENDS+=		xdpyinfo-[0-9]*:../../x11/xdpyinfo
DEPENDS+=		xmessage-[0-9]*:../../x11/xmessage
DEPENDS+=		xhost-[0-9]*:../../x11/xhost
DEPENDS+=		xload-[0-9]*:../../x11/xload
DEPENDS+=		xwud-[0-9]*:../../x11/xwud
DEPENDS+=		xprop-[0-9]*:../../x11/xprop
DEPENDS+=		xrandr-[0-9]*:../../x11/xrandr
DEPENDS+=		x11perf-[0-9]*:../../x11/x11perf
DEPENDS+=		xeyes-[0-9]*:../../x11/xeyes
DEPENDS+=		xcalc-[0-9]*:../../x11/xcalc
DEPENDS+=		xkill-[0-9]*:../../x11/xkill
DEPENDS+=		xmag-[0-9]*:../../x11/xmag
DEPENDS+=		xman-[0-9]*:../../x11/xman
DEPENDS+=		xmore-[0-9]*:../../x11/xmore
DEPENDS+=		xlogo-[0-9]*:../../x11/xlogo
DEPENDS+=		xsetmode-[0-9]*:../../x11/xsetmode
DEPENDS+=		xsetpointer-[0-9]*:../../x11/xsetpointer
DEPENDS+=		xfontsel-[0-9]*:../../x11/xfontsel
DEPENDS+=		xgamma-[0-9]*:../../x11/xgamma
DEPENDS+=		xplsprinters-[0-9]*:../../x11/xplsprinters
DEPENDS+=		xprehashprinterlist-[0-9]*:../../x11/xprehashprinterlist
DEPENDS+=		xrefresh-[0-9]*:../../x11/xrefresh
DEPENDS+=		xsm-[0-9]*:../../x11/xsm
DEPENDS+=		xvinfo-[0-9]*:../../x11/xvinfo
DEPENDS+=		xwininfo-[0-9]*:../../x11/xwininfo
DEPENDS+=		twm-[0-9]*:../../wip/twm

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
