# $NetBSD: Makefile,v 1.1.1.1 2005/12/30 18:21:51 kuli0020 Exp $

DISTNAME=	Module-Install-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Module-Install/
COMMENT=	Standalone, extensible Perl module installer
PERL5_REQD+=    5.6.0

BUILD_DEPENDS+=	{perl>=5.8.5,p5-podlators>=0}:../../wip/p5-podlators
BUILD_DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Module-ScanDeps>=0.28:../../devel/p5-Module-ScanDeps
BUILD_DEPENDS+=	p5-Module-CoreList>=0:../../devel/p5-Module-CoreList
BUILD_DEPENDS+=	p5-Module-Build>=0:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-PAR-Dist>=0.03:../../devel/p5-PAR-Dist
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=0:../../wip/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-CPANPLUS>=0.04:../../wip/p5-CPANPLUS
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

PERL5_PACKLIST= auto/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
