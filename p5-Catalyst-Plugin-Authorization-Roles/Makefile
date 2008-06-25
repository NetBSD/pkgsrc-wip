# $NetBSD: Makefile,v 1.3 2008/06/25 09:20:57 absd Exp $

DISTNAME=	Catalyst-Plugin-Authorization-Roles-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authorization-Roles/
COMMENT=	Role based authorization for Catalyst

DEPENDS+=	p5-Catalyst>=5.49:../../wip/p5-Catalyst
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.03:../../wip/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Set-Object>=1.14:../../devel/p5-Set-Object
DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
DEPENDS+=	p5-UNIVERSAL-isa>=0.05:../../devel/p5-UNIVERSAL-isa

# PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authorization/Roles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
