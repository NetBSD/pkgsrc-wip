# $NetBSD: Makefile,v 1.1.1.1 2009/11/19 05:59:52 obache Exp $
#

DISTNAME=	libbind-6.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/libbind/6.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://www.isc.org/software/libbind
COMMENT=	Standard Resolver Library
#LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	nroff tbl

MAKE_JOBS_SAFE=	no

BUILD_TARGET=	all man

.include "../../mk/bsd.pkg.mk"
