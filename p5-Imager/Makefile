# $NetBSD: Makefile,v 1.15 2015/07/14 15:45:29 fhajny Exp $

DISTNAME=		Imager-1.012
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		graphics perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Imager/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		https://metacpan.org/release/Imager
COMMENT=		Perl module for manipulating gray, color, and RGBA format images
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Imager/.packlist

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
