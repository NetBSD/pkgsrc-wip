# $NetBSD: Makefile,v 1.11 2012/11/13 19:33:45 othyro Exp $

DISTNAME=	openvrml-0.14.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvrml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvrml.org/
COMMENT=	Portable C++ library for displaying VRML97 files


GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-script-node-java --disable-script-node-javascript
USE_TOOLS+=		gmake

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
