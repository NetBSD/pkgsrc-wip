# $NetBSD: Makefile,v 1.8 2010/01/18 09:38:28 thomasklausner Exp $

DISTNAME=		Imager-0.70
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Imager/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/~tonyc/Imager/
COMMENT=		Perl module for manipulating gray, color, and RGBA format images

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=		--disable gif

SUBST_CLASSES+=		ft1
SUBST_STAGE.ft1=	post-configure
SUBST_FILES.ft1=	Makefile
SUBST_SED.ft1=		-e 's,-I/usr/local/include/freetype ,,g'

PERL5_PACKLIST= 	auto/Imager/.packlist

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
