# $NetBSD: Makefile,v 1.1.1.1 2009/08/19 18:09:29 udontknow Exp $
#

DISTNAME=	libzdb-2.6
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
