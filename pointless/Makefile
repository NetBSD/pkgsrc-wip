# $NetBSD: Makefile,v 1.22 2012/10/05 13:52:02 asau Exp $
#

DISTNAME=		pointless-0.5
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pointless/}

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://pointless.sourceforge.net/
COMMENT=		Markup-language presentation tool

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

DEPENDS+=		a2ps>=4.1:../../print/a2ps
DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=		pdflib>=4.0.3:../../print/pdflib
DEPENDS+=		plotutils>=2.4.1:../../graphics/plotutils
DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		freetype2>=2.1:../../graphics/freetype2
DEPENDS+=		ghostscript>=7.0:../../print/ghostscript
DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=		tex-tex-[0-9]*:../../print/tex-tex

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes

CPPFLAGS=		-DHAVE_PYTHON${PYVERSSUFFIX:S/./_/}
CONFIGURE_ARGS+=	--enable-sdl=no

INSTALL_TARGET=		${INSTALL} install-modules

.include "../../lang/python/application.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
