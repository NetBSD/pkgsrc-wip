# $NetBSD: Makefile,v 1.7 2014/05/31 15:57:19 thomasklausner Exp $
#

DISTNAME=		gfontview-0.5.0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gfontview/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://gfontview.sourceforge.net/
COMMENT=		Outline font viewer for X11


USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-fontdir=${LOCALBASE}/share/ghostscript/fonts

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
