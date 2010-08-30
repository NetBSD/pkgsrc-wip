# $NetBSD: Makefile,v 1.1.1.1 2010/08/30 19:21:32 ondratu Exp $
#

DISTNAME=	teng-2.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=teng/}

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ondrej.tuma@firma.seznam.cz
HOMEPAGE=	http://teng.sourceforge.net/
COMMENT=	Teng is a general purpose templating engine (whence Teng)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=     aclocal autoconf automake bison

pre-configure:
	cd ${WRKSRC} && aclocal && libtoolize --force && automake --add-missing && autoconf

#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
