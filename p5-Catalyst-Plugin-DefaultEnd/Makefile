# $NetBSD: Makefile,v 1.5 2013/04/03 01:27:02 jgoamakf Exp $

DISTNAME=	Catalyst-Plugin-DefaultEnd-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/B/BO/BOBTFISH/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-DefaultEnd
COMMENT=	Sensible default end action
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.20:../../www/p5-Catalyst-Runtime

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Catalyst/Plugin/DefaultEnd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
