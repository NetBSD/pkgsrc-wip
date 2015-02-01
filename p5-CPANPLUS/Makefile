# $NetBSD: Makefile,v 1.7 2015/02/01 08:36:42 makoto Exp $

DISTNAME=	CPANPLUS-0.9152
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPANPLUS/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://cpanplus.sourceforge.net/
COMMENT=	Ameliorated interface to the CPAN
LICENSE=	${PERL5_LICENSE}

INSTALL_TARGET=	pure_install

DEPENDS+=	p5-Test-Reporter-[0-9]*:../../devel/p5-Test-Reporter
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

PERL5_PACKLIST= auto/CPANPLUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
