# $NetBSD: Makefile,v 1.1.1.1 2004/03/21 21:04:23 bjan2 Exp $

DISTNAME=	openvrml-0.14.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvrml/}

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.openvrml.org/
COMMENT=	Portable C++ library for displaying VRML97 files

USE_X11=	YES
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--disable-script-node-java --disable-script-node-javascript
USE_GNU_TOOLS+=	make

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
