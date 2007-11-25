# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 04:14:21 philnelson Exp $

DISTNAME=		PDF-Reuse-Barcode-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~larslund/PDF-Reuse-Barcode-0.05
COMMENT=		Create barcodes for PDF documents with PDF::Reuse

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-PDF-Reuse>=0.33:../../wip/p5-PDF-Reuse
DEPENDS+=		p5-GD-Barcode>=1.15:../../wip/p5-GD-Barcode
DEPENDS+=		p5-Barcode-Code128>=2.01:../../wip/p5-Barcode-Code128

PERL5_PACKLIST=	auto/PDF/Reuse/Barcode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
