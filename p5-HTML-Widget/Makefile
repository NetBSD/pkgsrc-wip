# $NetBSD: Makefile,v 1.9 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=		HTML-Widget-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/HTML-Widget
COMMENT=		HTML Widget And Validation Framework

DEPENDS+=		p5-Module-Pluggable-Fast>=0.18:../../wip/p5-Module-Pluggable-Fast
DEPENDS+=		p5-Class-Data-Accessor>=0.04001:../../devel/p5-Class-Data-Accessor
DEPENDS+=		p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings
DEPENDS+=		p5-HTML-Tree>=3.19.01:../../www/p5-HTML-Tree
DEPENDS+=		p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Class-Accessor-Chained>=0.01:../../devel/p5-Class-Accessor-Chained
DEPENDS+=		p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=		p5-Test-MockObject>=1.02:../../devel/p5-Test-MockObject
DEPENDS+=		p5-Email-Valid>=0.15:../../mail/p5-Email-Valid
DEPENDS+=		p5-Date-Calc>=5.4:../../devel/p5-Date-Calc

PERL5_PACKLIST=		auto/HTML/Widget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
