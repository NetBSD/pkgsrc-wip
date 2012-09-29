# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:39 asau Exp $
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

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
