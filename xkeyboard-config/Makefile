# $NetBSD: Makefile,v 1.1.1.1 2006/12/05 03:01:34 jeremy-c-reed Exp $
#

DISTNAME=	xkeyboard-config-0.9
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/xkbdesc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.freedesktop.org/wiki/Software_2fXKeyboardConfig
COMMENT=	X Keyboard Configuration Database

# xorg has deprecated xkbdata; xorg says to use xkeyboard-config instead
CONFLICTS+=	xkbdata-[0-9]*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake intltool

CONFIGURE_ARGS+=	--disable-xkbcomp-symlink 
CONFIGURE_ARGS+=	--with-xkb-base=${PREFIX}/share/X11/xkb

.include "../../mk/bsd.pkg.mk"
