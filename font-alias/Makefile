# $NetBSD: Makefile,v 1.1 2007/01/24 07:42:51 bsadewitz Exp $
#

DISTNAME=	font-alias-1.0.1
CATEGORIES=	fonts x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/font/
COMMENT=	Modular X.org font aliases

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-top-fontdir=${X11BASE:Q}/lib/X11/fonts

.include "../../mk/bsd.pkg.mk"
