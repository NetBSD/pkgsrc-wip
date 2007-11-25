# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 03:57:26 philnelson Exp $

DISTNAME=		PDF-Reuse-0.33
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~larslund/PDF-Reuse-0.33
COMMENT=		Perl module to reuse PDF templates

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Compress-Zlib>=2.004:../../devel/p5-Compress-Zlib
DEPENDS+=		p5-Digest-MD5>=2.35:../../security/p5-Digest-MD5

PERL5_PACKLIST=	auto/PDF/Reuse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
