# $NetBSD: Makefile,v 1.10 2006/09/13 18:50:46 peterih Exp $
#

DISTNAME=		pointless-0.5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++

DEPENDS+=               a2ps>=4.1:../../print/a2ps
DEPENDS+=               pdflib>=4.0.3:../../print/pdflib
DEPENDS+=               plotutils>=2.4.1:../../graphics/plotutils
DEPENDS+=               gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=               freetype2>=2.1:../../graphics/freetype2
DEPENDS+=               Mesa>=6.0:../../graphics/Mesa
DEPENDS+=               ghostscript-esp>=7.0:../../print/ghostscript-esp

USE_PKGLOCALEDIR=       yes

INSTALL_TARGET=		${INSTALL} install-modules

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python22/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
