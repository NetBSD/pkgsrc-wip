# $NetBSD: Makefile,v 1.1.1.1 2007/11/22 01:48:51 geeohgeegeeoh Exp $

PKGVERSION=	0.07000
DISTNAME=	Class-Accessor-Grouped-${PKGVERSION}
PKGNAME=	p5-Class-Accessor-Grouped-${PKGVERSION}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	ggm@apnic.net
COMMENT=	Class::Accessor::Grouped

DEPENDS+=	p5-Class-C3>=0:../../wip/p5-Class-C3
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-MRO-Compat>=0:../../wip/p5-MRO-Compat

PERL5_PACKLIST=	auto/Class/Accessor/Grouped/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
