# $NetBSD: Makefile,v 1.5 2004/10/29 21:51:59 bencollver Exp $
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
NOT_FOR_PLATFORM=	NetBSD-1.6.2-*

.include "../../mk/bsd.pkg.mk"
