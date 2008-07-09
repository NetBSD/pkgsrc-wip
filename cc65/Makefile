# $NetBSD: Makefile,v 1.2 2008/07/09 16:31:03 christtrekker Exp $
#

DISTNAME=	cc65-sources-2.12.0
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	cross lang
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.cc65.org/
COMMENT=	C cross compiler for 6502 target systems

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	make/gcc.mak
USE_TOOLS+=	gmake

NOT_FOR_PLATFORM+=	NetBSD-*-*

.include "../../mk/bsd.pkg.mk"
