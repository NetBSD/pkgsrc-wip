# $NetBSD: Makefile,v 1.1.1.1 2004/07/13 17:04:31 cetrox Exp $
#

DISTNAME=		gfontview-0.5.0
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gfontview/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://gfontview.sourceforge.net/
COMMENT=		Outline font viewer for X11

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-fontdir=${LOCALBASE}/share/ghostscript/fonts

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
