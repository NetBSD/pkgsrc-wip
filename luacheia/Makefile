# $NetBSD: Makefile,v 1.1.1.1 2004/01/23 00:28:05 poppnk Exp $
#

DISTNAME=		luacheia5-5.0.1a4
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES
CPPFLAGS+=	"-I${PREFIX}/include"
CPPFLAGS+=	"-I/usr/X11R6/include"
LDFLAGS+=	"-L${PREFIX}/lib"
LDFLAGS+=	"-L/usr/X11R6/lib"

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
