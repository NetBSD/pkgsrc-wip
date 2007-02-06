# $NetBSD: Makefile,v 1.1.1.1 2007/02/06 09:28:18 netcap Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-DBI-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-Store-DBI/
COMMENT=	DBI storage backend for session data

DEPENDS+=	p5-Catalyst>=5.0:../../wip/p5-Catalyst
DEPENDS+=	p5-DBI>=1.50:../../databases/p5-DBI
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.01:../../wip/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable

PERL5_REQD+=	5.8.0
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/Store/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
