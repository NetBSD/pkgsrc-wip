# $NetBSD: Makefile,v 1.1.1.1 2008/07/02 13:36:31 christtrekker Exp $
#

DISTNAME=	cc65-sources-2.12.0
PKGNAME=	cc65-2.12.0
CATEGORIES=	cross lang
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.cc65.org/
COMMENT=	C cross compiler for 6502 target systems

WRKSRC=	${WRKDIR}/cc65-2.12.0
MAKE_FILE=	${WRKSRC}/make/gcc.mak
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
