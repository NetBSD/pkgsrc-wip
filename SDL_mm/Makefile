# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 03:19:48 xtraeme Exp $
#

DISTNAME=	SDLmm-0.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
