# $NetBSD: Makefile,v 1.3 2013/03/02 13:22:43 tnn2 Exp $
#

DISTNAME=	libzdb-2.11.1
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	zdb.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
