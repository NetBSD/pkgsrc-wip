# $NetBSD: Makefile,v 1.1.1.1 2009/04/11 12:57:45 jihbed Exp $
#

DISTNAME=	libmrss-0.19.2
CATEGORIES=	www
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.autistici.org/bakunin/libmrss/
COMMENT=	Libmrss is a C library manipulate rss files or streams

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES =	c c++

PKGCONFIG_OVERRIDE+=	mrss.pc.in

.include "../../wip/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
