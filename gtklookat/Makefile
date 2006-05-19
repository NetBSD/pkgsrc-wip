# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:18 ykomatsu Exp $

DISTNAME=	gtklookat-0.13.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvrml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvrml.org/
COMMENT=	GTK VRML97 viewer

GNU_CONFIGURE=	YES
#CONFIGURE_ARGS+=--disable-script-node-java --disable-script-node-javascript
USE_TOOLS+=	gmake
LIBS+=		-lX11

.include "../../wip/openvrml/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
