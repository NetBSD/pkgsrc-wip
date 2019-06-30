# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Math-Gauss-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Gauss
COMMENT=	Perl module for Gaussian probability distribution

LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/Gauss/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
