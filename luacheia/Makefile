# $NetBSD: Makefile,v 1.11 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=		luacheia5-5.0.1a4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=/luacheia/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://luacheia.sourceforge.net/
COMMENT=		Extension libraries for LUA

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
CPPFLAGS+=	-I${PREFIX:Q}/include
CPPFLAGS+=	-I/usr/X11R6/include
LDFLAGS+=	-L${PREFIX:Q}/lib
LDFLAGS+=	-L/usr/X11R6/lib

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
