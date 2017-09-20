# $NetBSD: Makefile,v 1.24 2015/11/15 04:54:38 wen Exp $

DISTNAME=		OptArgs-0.1.20
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/OptArgs/
COMMENT=		Extended processing of command line options
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Exporter-Tidy-[0-9]*:../../wip/p5-Exporter-Tidy
DEPENDS+=		p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
BUILD_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=		p5-Test-Output-[0-9]*:../../devel/p5-Test-Output

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/OptArgs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
