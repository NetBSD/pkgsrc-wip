# $NetBSD: Makefile,v 1.1.1.1 2005/09/09 18:42:07 kuli0020 Exp $

DISTNAME=	Imager-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Imager/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://www.eecs.umich.edu/~addi/perl/Imager/
COMMENT=	A Perl module for manipulating gray, color and rgba format images

DEPENDS+=	t1lib>=0:../../fonts/t1lib
DEPENDS+=	tiff>=0:../../graphics/tiff
DEPENDS+=	png>=0:../../graphics/png
DEPENDS+=	jpeg>=0:../../graphics/jpeg

USE_FREETYPE=	yes
CONFIGURE_ENV+=	IM_LIBPATH="${LOCALBASE}/lib"
CONFIGURE_ENV+=	IM_INCPATH="${LOCALBASE}/include/freetype1/freetype"
USE_TOOLS+=	gmake

PERL5_PACKLIST= auto/Imager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
