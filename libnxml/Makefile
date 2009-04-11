# $NetBSD: Makefile,v 1.1.1.1 2009/04/11 12:53:42 jihbed Exp $
#

DISTNAME=	libnxml-0.18.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libnxml/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.autistici.org/bakunin/libmrss/doc/index.html
COMMENT=	C library for XML 1.0 and 1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	nxml.pc.in

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
