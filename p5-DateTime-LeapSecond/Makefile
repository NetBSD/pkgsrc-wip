# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 12:12:23 cubidou Exp $

DISTNAME=		DateTime-LeapSecond-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/DateTime-LeapSecond/
COMMENT=		Perl module to handle leap seconds

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/LeapSecond/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
