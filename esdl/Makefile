# $NetBSD: Makefile,v 1.2 2005/10/10 14:00:12 rillig Exp $

DISTNAME=	esdl-0.95.0630.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esdl/}

MAINTAIER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://esdl.sourceforge.net/
COMMENT=	SDL and OpenGL library for Erlang

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake
BUILD_TARGET=	target

DEPENDS+=	erlang>=9:../../lang/erlang
BUILDLINK_PASSTHRU_DIRS+=	${LOCALBASE}/lib/erlang

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
