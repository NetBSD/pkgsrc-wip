# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 12:25:38 cubidou Exp $

DISTNAME=		DateTime-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://datetime.perl.org/
COMMENT=		Perl module for date/time sets and ranges

DEPENDS+=		p5-Class-Factory-Util-[0-9]*:../../wip/p5-Class-Factory-Util
DEPENDS+=		p5-DateTime-LeapSecond-[0-9]*:../../wip/p5-DateTime-LeapSecond
DEPENDS+=		p5-DateTime-TimeZone-[0-9]*:../../wip/p5-DateTime-TimeZone
DEPENDS+=		p5-Params-Validate>=0.52:../../devel/p5-Params-Validate
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
