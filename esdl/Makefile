# $NetBSD: Makefile,v 1.7 2012/09/28 22:07:35 asau Exp $

DISTNAME=	esdl-0.95.0630.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esdl/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://esdl.sourceforge.net/
COMMENT=	SDL and OpenGL library for Erlang

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake
BUILD_TARGET=	target

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
