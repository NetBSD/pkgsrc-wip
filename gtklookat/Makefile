# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:57 tvierling Exp $

DISTNAME=	gtklookat-0.13.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvrml/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openvrml.org/
COMMENT=	GTK VRML97 viewer

USE_X11=	YES
GNU_CONFIGURE=	YES
#CONFIGURE_ARGS+=--disable-script-node-java --disable-script-node-javascript
USE_GNU_TOOLS+=	make
LIBS+=		-lX11

.include "../../wip/openvrml/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
