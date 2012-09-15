# $NetBSD: Makefile,v 1.1 2012/09/15 21:58:24 jihbed Exp $
#

DISTNAME=	libpsurface-1.3.1
CATEGORIES=	math
MASTER_SITES=	http://numerik.mi.fu-berlin.de/dune/psurface/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://numerik.mi.fu-berlin.de/dune/psurface/index.php
COMMENT=	Library that handles piecewise linear bijections
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE= yes
USE_LIBTOOL= yes
USE_TOOLS+=	pkg-config gmake m4 aclocal \
		autoconf automake autoreconf
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-amiramesh

pre-configure:
	cd ${WRKSRC} && autoreconf -isf


.include "../../mk/bsd.pkg.mk"
