# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 16:27:58 mpasternak Exp $
#

DISTNAME=		maxima-5.9.0
CATEGORIES=		science
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Sophisticated computer algebra system

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# ... when it's ready:

.include "../../gcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
