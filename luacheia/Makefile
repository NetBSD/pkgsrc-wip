# $NetBSD: Makefile,v 1.5 2005/04/11 21:13:56 tvierling Exp $
#

DISTNAME=		luacheia5-5.0.1a4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
CPPFLAGS+=	"-I${PREFIX}/include"
CPPFLAGS+=	"-I/usr/X11R6/include"
LDFLAGS+=	"-L${PREFIX}/lib"
LDFLAGS+=	"-L/usr/X11R6/lib"

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
