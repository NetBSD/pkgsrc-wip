# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 04:03:42 philnelson Exp $
#

DISTNAME=	GD-Barcode-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://search.cpan.org/~kwitknr/GD-Barcode-1.15
COMMENT=	GD-Barcode is package to create barcodes with GD

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD

PERL5_PACKLIST=		auto/GD/Barcode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
