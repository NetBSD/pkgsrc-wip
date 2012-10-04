# $NetBSD: Makefile,v 1.12 2012/10/04 10:45:30 asau Exp $

DISTNAME=		Imager-0.82
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		graphics perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Imager/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/~tonyc/Imager/
COMMENT=		Perl module for manipulating gray, color, and RGBA format images
LICENSE=		${PERL5_LICENSE}

#MAKE_PARAMS+=		--disable gif

SUBST_CLASSES+=		ft1
SUBST_STAGE.ft1=	post-configure
SUBST_FILES.ft1=	Makefile
SUBST_SED.ft1=		-e 's,-I/usr/local/include/freetype ,,g'

PERL5_PACKLIST=		auto/Imager/.packlist

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
