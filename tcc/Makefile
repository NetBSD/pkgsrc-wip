# $NetBSD: Makefile,v 1.6 2004/11/23 22:56:54 xtraeme Exp $
#

DISTNAME=	tcc-0.9.22
CATEGORIES=	lang
MASTER_SITES=	http://fabrice.bellard.free.fr/tcc/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.tinycc.org/
COMMENT=	The Smallest ANSI C compiler

ONLY_FOR_PLATFORM=      *-*-i386
NOT_FOR_PLATFORM=       NetBSD-1.6.2-*

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
