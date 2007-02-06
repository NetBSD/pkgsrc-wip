# $NetBSD: Makefile,v 1.2 2007/02/06 09:30:22 netcap Exp $

DISTNAME=	Catalyst-Plugin-Session-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session/
COMMENT=	Generic Catalyst Session plugin
PERL5_REQD+=	5.8.1

DEPENDS+=	p5-Catalyst>=5.50:../../wip/p5-Catalyst
DEPENDS+=	p5-Test-MockObject>=1.01:../../wip/p5-Test-MockObject
DEPENDS+=	p5-Digest>=0:../../security/p5-Digest
DEPENDS+=	p5-Object-Signature>=0:../../wip/p5-Object-Signature
DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

# PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
