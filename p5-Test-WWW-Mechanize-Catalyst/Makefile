# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 21:32:43 kuli0020 Exp $

DISTNAME=	Test-WWW-Mechanize-Catalyst-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LB/LBROCARD/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Mechanize-Catalyst/
COMMENT=	Test::WWW::Mechanize for Catalyst

DEPENDS+=	p5-Catalyst>=5.00:../../wip/p5-Catalyst
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-WWW-Mechanize>=1.04:../../www/p5-Test-WWW-Mechanize

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Test/WWW/Mechanize/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
