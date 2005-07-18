# $NetBSD: Makefile,v 1.7 2005/07/18 14:38:41 peterih Exp $
#

DISTNAME=		pointless-0.5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

DEPENDS+=               a2ps>=4.1:../../print/a2ps
DEPENDS+=               gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=               teTeX>=2.0:../../print/teTeX
DEPENDS+=               Mesa>=6.0:../../graphics/Mesa
DEPENDS+=               ghostscript-esp-nox11>=7.0:../../print/ghostscript-esp-nox11

USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		${INSTALL} install-modules

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python22/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
