# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 18:53:05 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Authentication-Store-DBIC-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-Store-DBIC/
COMMENT=	Authentication/authorization on a DBIx::Class/Class::DBI model

DEPENDS+=	p5-Catalyst>=5.49:../../wip/p5-Catalyst
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.03:../../wip/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles>=0.03:../../wip/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Set-Object>=0:../../wip/p5-Set-Object
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.02:../../wip/p5-Catalyst-Plugin-Session

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/Store/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
