# $NetBSD: Makefile,v 1.7 2005/06/12 23:51:22 kristerw Exp $
#

DISTNAME=		luacheia5-5.0.1a4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
CPPFLAGS+=	"-I${PREFIX}/include"
CPPFLAGS+=	"-I/usr/X11R6/include"
LDFLAGS+=	"-L${PREFIX}/lib"
LDFLAGS+=	"-L/usr/X11R6/lib"

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
