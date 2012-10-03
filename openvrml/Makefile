# $NetBSD: Makefile,v 1.10 2012/10/03 21:32:47 asau Exp $

DISTNAME=	openvrml-0.14.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvrml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvrml.org/
COMMENT=	Portable C++ library for displaying VRML97 files

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--disable-script-node-java --disable-script-node-javascript
USE_TOOLS+=	gmake

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
