# $NetBSD: Makefile,v 1.1 2015/01/28 09:42:19 makoto Exp $

DISTNAME=		Module-CPANTS-Analyse-0.96
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-CPANTS-Analyse/
COMMENT=		Perl5 module to generate Kwalitee ratings for a distribution
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile>=0:../../devel/p5-ExtUtils-MakeMaker-CPANfile
DEPENDS+=	p5-Module-CPANfile>=0:../../devel/p5-Module-CPANfile

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/CPANTS/Analyse/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
