# $NetBSD: Makefile,v 1.1 2007/03/28 18:49:45 bsadewitz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-utils-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg utilities meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	 xrestop-[0-9]*:../../x11/xrestop
DEPENDS+=	 appres-[0-9]*:../../x11/appres
DEPENDS+=	 iceauth-[0-9]*:../../x11/iceauth
DEPENDS+=	 xbitmaps-[0-9]*:../../x11/xbitmaps
DEPENDS+=	 xinit-[0-9]*:../../x11/xinit
DEPENDS+=	 xauth-[0-9]*:../../x11/xauth
DEPENDS+=	 xmodmap-[0-9]*:../../x11/xmodmap
DEPENDS+=	 xrdb-[0-9]*:../../x11/xrdb
DEPENDS+=	 xset-[0-9]*:../../x11/xset
DEPENDS+=	 xsetroot-[0-9]*:../../x11/xsetroot
DEPENDS+=	 xev-[0-9]*:../../x11/xev
DEPENDS+=	 xwd-[0-9]*:../../x11/xwd
DEPENDS+=	 xclock-[0-9]*:../../x11/xclock
DEPENDS+=	 xconsole-[0-9]*:../../x11/xconsole
DEPENDS+=	 xdpyinfo-[0-9]*:../../x11/xdpyinfo
DEPENDS+=	 xmessage-[0-9]*:../../x11/xmessage
DEPENDS+=	 xhost-[0-9]*:../../x11/xhost
DEPENDS+=	 xload-[0-9]*:../../x11/xload
DEPENDS+=	 xwud-[0-9]*:../../x11/xwud
DEPENDS+=	 xprop-[0-9]*:../../x11/xprop
DEPENDS+=	 xrandr-[0-9]*:../../x11/xrandr
DEPENDS+=	 setxkbmap-[0-9]*:../../x11/setxkbmap

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
