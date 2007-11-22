# $NetBSD: Makefile,v 1.1.1.1 2007/11/22 01:20:06 geeohgeegeeoh Exp $

PKGVERSION=	1.0001
DISTNAME=	Class-C3-Componentised-${PKGVERSION}
PKGNAME=	p5-Class-C3-Componentised-${PKGVERSION}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASH/}

MAINTAINER=	ggm@apnic.net
COMMENT=	Class::C3::Componentised

DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

PERL5_PACKLIST=	auto/Class/C3/Componentised/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
