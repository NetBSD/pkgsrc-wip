# $NetBSD: Makefile,v 1.5 2012/10/04 09:13:27 asau Exp $

DISTNAME=	CPANPLUS-0.0562
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KANE/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://cpanplus.sourceforge.net/
COMMENT=	Ameliorated interface to the CPAN
PERL5_REQD+=	5.6.0

PKG_DESTDIR_SUPPORT=	none

MAKE_PARAMS=	AUTOINSTALL=1 JFDI=1
INSTALL_TARGET=	pure_install

OPTIONS+=	TEST_REPORTER "Send reports to cpan-testers" off
OPTIONS+=	YAML "Check reports from cpan-testers" off

.if defined(WITH_TEST_REPORTER)
DEPENDS+=	p5-Test-Reporter:../../devel/p5-Test-Reporter
.endif

.if defined(WITH_YAML)
DEPENDS+=	p5-YAML.pm:../../textproc/p5-YAML
.endif

PERL5_PACKLIST= auto/CPANPLUS/.packlist

post-extract:
	${MV} ${WRKSRC}/lib/CPANPLUS/Config.pm-orig ${WRKSRC}/lib/CPANPLUS/Config.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
