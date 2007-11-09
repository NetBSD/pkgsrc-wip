# $NetBSD: Makefile,v 1.5 2007/11/09 03:01:23 bsadewitz Exp $
#

DISTNAME=	xkeyboard-config-1.1
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/xkbdesc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.freedesktop.org/wiki/Software_2fXKeyboardConfig
COMMENT=	X Keyboard Configuration Database

PKG_DESTDIR_SUPPORT=	user-destdir

# xorg has deprecated xkbdata; xorg says to use xkeyboard-config instead
CONFLICTS+=	xkbdata-[0-9]*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake intltool perl:build msgfmt msgmerge xgettext

BUILD_DEPENDS+=	xkbcomp-[0-9]*:../../x11/xkbcomp

CONFIGURE_ARGS+=	--with-xkb-rules-symlink=xorg
CONFIGURE_ARGS+=	--with-xkb-base=${PREFIX}/share/X11/xkb
CONFIGURE_ARGS+=	--without-xkbcomp-symlink

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
