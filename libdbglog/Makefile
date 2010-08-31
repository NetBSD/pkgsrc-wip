# $NetBSD: Makefile,v 1.1.1.1 2010/08/31 08:46:10 ondratu Exp $
#

DISTNAME=	libdbglog-1.5.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbglog/}

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ondrej.tuma@firma.seznam.cz
HOMEPAGE=	http://opensource.seznam.cz/DBGlog
COMMENT=	C++ library for debugging purposes and runtime logging to file

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=     aclocal autoconf automake

pre-configure:
	cd ${WRKSRC} && aclocal && libtoolize --force && automake --foreign --add-missing && autoconf

#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
