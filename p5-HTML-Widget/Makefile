# $NetBSD: Makefile,v 1.1.1.1 2006/02/16 11:18:22 jgoamakf Exp $

DISTNAME=		HTML-Widget-1.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTML-Widget/
COMMENT=		HTML Widget And Validation Framework

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-HTML-Tree>=3.19.01:../../www/p5-HTML-Tree
DEPENDS+=		p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Class-Accessor-Chained>=0.01:../../wip/p5-Class-Accessor-Chained
DEPENDS+=		p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=		p5-Test-MockObject>=1.02:../../wip/p5-Test-MockObject
DEPENDS+=		p5-Email-Valid>=0.15:../../mail/p5-Email-Valid
DEPENDS+=		p5-Date-Calc>=5.4:../../devel/p5-Date-Calc

PERL5_PACKLIST=		auto/HTML/Widget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
