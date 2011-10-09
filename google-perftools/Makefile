# $NetBSD: Makefile,v 1.4 2011/10/09 10:05:44 cheusov Exp $
#

DISTNAME=	google-perftools-1.5
CATEGORIES=	devel
MASTER_SITES=	http://google-perftools.googlecode.com/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://google-perftools.googlecode.com/
COMMENT=	Multi-threaded malloc() and nifty performance analysis tools

LICENSE=	modified-bsd

USE_TOOLS+=		perl:run
REPLACE_PERL=		src/pprof
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
