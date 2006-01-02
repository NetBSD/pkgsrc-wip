# $NetBSD: Makefile,v 1.8 2006/01/02 08:54:56 rillig Exp $
#

DISTNAME=		luacheia5-5.0.1a4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
CPPFLAGS+=	-I${PREFIX:Q}/include
CPPFLAGS+=	-I/usr/X11R6/include
LDFLAGS+=	-L${PREFIX:Q}/lib
LDFLAGS+=	-L/usr/X11R6/lib

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
