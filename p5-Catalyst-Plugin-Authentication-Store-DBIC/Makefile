# $NetBSD: Makefile,v 1.5 2008/10/20 10:10:18 tonnerre Exp $

DISTNAME=	Catalyst-Plugin-Authentication-Store-DBIC-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-Store-DBIC/
COMMENT=	Authentication/authorization on a DBIx::Class/Class::DBI model

DEPENDS+=	p5-Catalyst-Runtime>=5.49:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.06:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles>=0.03:../../www/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie>=0.02:../../www/p5-Catalyst-Plugin-Session-State-Cookie
DEPENDS+=	p5-Set-Object>=1.14:../../devel/p5-Set-Object
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Class-DBI>=0:../../databases/p5-Class-DBI
DEPENDS+=	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0:../../www/p5-Test-WWW-Mechanize-Catalyst
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0:../../databases/p5-Catalyst-Model-DBIC-Schema



PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/Store/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
