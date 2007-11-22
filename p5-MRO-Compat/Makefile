# $NetBSD: Makefile,v 1.1.1.1 2007/11/22 01:38:39 geeohgeegeeoh Exp $

PKGVERSION=	0.05
DISTNAME=	MRO-Compat-${PKGVERSION}
PKGNAME=	p5-MRO-Compat-${PKGVERSION}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLBLACK/}

MAINTAINER=	ggm@apnic.net
COMMENT=	MRO::Compat

DEPENDS+=	p5-Class-C3>=0:../../wip/p5-Class-C3
DEPENDS+=	p5-Class-C3-XS>=0:../../wip/p5-Class-C3-XS

PERL5_PACKLIST=	auto/MRO/Compat/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
