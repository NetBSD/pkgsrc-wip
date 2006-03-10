# $NetBSD: Makefile,v 1.1.1.1 2006/03/10 20:30:18 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-StackTrace-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-StackTrace/
COMMENT=	Display a stack trace on the debug screen
PERL5_REQD+=	5.8.0

DEPENDS+=	p5-Catalyst>=5.61:../../wip/p5-Catalyst
DEPENDS+=	p5-Devel-StackTrace>=0:../../devel/p5-Devel-StackTrace

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/Catalyst/Plugin/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
