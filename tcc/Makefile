# $NetBSD: Makefile,v 1.3 2004/01/25 02:33:44 grantbeattie Exp $
#

DISTNAME=	tcc-0.9.19
CATEGORIES=	lang
MASTER_SITES=	http://fabrice.bellard.free.fr/tcc/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.tinycc.org/
COMMENT=	The Smallest ANSI C compiler

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.pkg.mk"
