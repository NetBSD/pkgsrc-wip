# $NetBSD: Makefile,v 1.5 2012/11/23 22:33:50 othyro Exp $
#

DISTNAME=	Math-FixedPrecision-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
COMMENT=	Perl module that provides decimal math without floating point errors

REPLACE_PERL+=	FixedPrecision.pm
REPLACE_PERL+=	t/test.t

DEPENDS+=	p5-Math-BigInteger-*:../../math/p5-Math-BigInteger

PERL5_PACKLIST=	auto/Math/FixedPrecision/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
