# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 12:20:08 cubidou Exp $

DISTNAME=		DateTime-TimeZone-0.19
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=		Perl module to handle time zone manipulation

DEPENDS+=		p5-Class-Singleton-[0-9]*:../../local/p5-Class-Singleton
DEPENDS+=		p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/TimeZone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
