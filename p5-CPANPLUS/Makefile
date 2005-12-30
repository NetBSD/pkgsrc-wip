# $NetBSD: Makefile,v 1.1.1.1 2005/12/30 18:13:57 kuli0020 Exp $

DISTNAME=	CPANPLUS-0.0562
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KANE/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://cpanplus.sourceforge.net/
COMMENT=	Ameliorated interface to the CPAN
PERL5_REQD+=    5.6.0

CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

OPTIONS+=	TEST_REPORTER "Send reports to cpan-testers" off
OPTIONS+=	YAML "Check reports from cpan-testers" off

.if defined(WITH_TEST_REPORTER)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:../../devel/p5-Test-Reporter
.endif

.if defined(WITH_YAML)
BUILD_DEPENDS+=	${SITE_PERL}/YAML.pm:../../textproc/p5-YAML
.endif

PERL5_PACKLIST= auto/CPANPLUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
