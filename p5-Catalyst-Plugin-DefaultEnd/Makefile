# $NetBSD: Makefile,v 1.1.1.1 2006/03/07 19:30:40 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-DefaultEnd-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-DefaultEnd/
COMMENT=	Sensible default end action
PERL5_REQD+=	5.8.1

DEPENDS+=	p5-Catalyst>=5.20:../../wip/p5-Catalyst

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Catalyst/Plugin/DefaultEnd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
