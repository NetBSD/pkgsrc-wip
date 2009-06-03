# $NetBSD: Makefile,v 1.2 2009/06/03 08:57:09 thomasklausner Exp $
#

DISTNAME=	libmrss-0.19.2
CATEGORIES=	www
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.autistici.org/bakunin/libmrss/
COMMENT=	C library for parsing, writing and creating RSS files or streams

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES =	c c++

PKGCONFIG_OVERRIDE+=	mrss.pc.in

.include "../../textproc/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
