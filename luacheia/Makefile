# $NetBSD: Makefile,v 1.3 2004/04/12 02:38:39 blef Exp $
#

DISTNAME=		luacheia5-5.0.1a4
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
CPPFLAGS+=	"-I${PREFIX}/include"
CPPFLAGS+=	"-I/usr/X11R6/include"
LDFLAGS+=	"-L${PREFIX}/lib"
LDFLAGS+=	"-L/usr/X11R6/lib"

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
