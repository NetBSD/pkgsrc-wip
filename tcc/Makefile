# $NetBSD: Makefile,v 1.4 2004/03/17 22:56:05 xtraeme Exp $
#

DISTNAME=	tcc-0.9.20
CATEGORIES=	lang
MASTER_SITES=	http://fabrice.bellard.free.fr/tcc/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.tinycc.org/
COMMENT=	The Smallest ANSI C compiler

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.pkg.mk"
