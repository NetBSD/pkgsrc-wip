# $NetBSD: Makefile,v 1.6 2006/06/12 16:28:55 thomasklausner Exp $

DISTNAME=	esdl-0.95.0630.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
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
