# $NetBSD: Makefile,v 1.5 2005/12/30 14:00:05 ghen Exp $

DISTNAME=	esdl-0.95.0630.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esdl/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://esdl.sourceforge.net/
COMMENT=	SDL and OpenGL library for Erlang

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake
BUILD_TARGET=	target

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
