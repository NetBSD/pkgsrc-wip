# $NetBSD: Makefile,v 1.1.1.1 2005/08/05 02:57:22 jgoamakf Exp $

DISTNAME=		Template-Timer-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ttm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Template-Timer/
COMMENT=		Rudimentary profiling for Template Toolkit

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Timer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
