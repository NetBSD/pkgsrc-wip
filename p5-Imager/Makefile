# $NetBSD: Makefile,v 1.5 2005/09/20 16:46:33 kuli0020 Exp $

DISTNAME=	Imager-0.45
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Imager/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~tonyc/Imager/
COMMENT=	A Perl module for manipulating gray, color and rgba format images

DEPENDS+=	t1lib>=0:../../fonts/t1lib
DEPENDS+=	tiff>=0:../../graphics/tiff
DEPENDS+=	png>=0:../../graphics/png
DEPENDS+=	jpeg>=0:../../graphics/jpeg

MAKE_ENV+=	IM_LIBPATH="${X11BASE}/lib:${LOCALBASE}/lib"
MAKE_ENV+=	IM_INCPATH="${X11BASE}/include:${LOCALBASE}/include"
MAKE_ENV+=	IM_CFLAGS="${CFLAGS}"

PERL5_PACKLIST= auto/Imager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
