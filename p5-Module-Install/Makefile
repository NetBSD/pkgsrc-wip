# $NetBSD: Makefile,v 1.5 2006/04/13 14:51:53 kuli0020 Exp $

DISTNAME=	Module-Install-0.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Module-Install/
COMMENT=	Standalone, extensible Perl module installer
PERL5_REQD+=	5.6.0

BUILD_DEPENDS+=	{perl>=5.8.5,p5-podlators>=0}:../../wip/p5-podlators
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.42}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Module-ScanDeps>=0.28:../../devel/p5-Module-ScanDeps
BUILD_DEPENDS+=	p5-Module-CoreList>=0:../../devel/p5-Module-CoreList
BUILD_DEPENDS+=	p5-Module-Build>=0:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-PAR-Dist>=0.03:../../devel/p5-PAR-Dist
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=0:../../wip/p5-ExtUtils-ParseXS
DEPENDS+=	p5-Archive-Tar>=0.23:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skipdeps
PERL5_PACKLIST=	auto/Module/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
