# $NetBSD: Makefile,v 1.24 2015/11/15 04:54:38 wen Exp $

DISTNAME=		OptArgs-0.1.18
PKGNAME=		p5-${DISTNAME:S/OptArgs/Getopt-Args/}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/OptArgs/
COMMENT=		Extended processing of command line options
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Exporter-Tidy>0:../../wip/p5-Exporter-Tidy
DEPENDS+=		p5-IO-Capture>0:../../devel/p5-IO-Capture

PERL5_PACKLIST=		auto/OptArgs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
