# $NetBSD: Makefile,v 1.3 2008/10/20 10:10:18 tonnerre Exp $

DISTNAME=	Catalyst-Plugin-Authentication-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication/
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

DEPENDS+=	p5-Catalyst-Runtime>=5.49:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=   p5-Catalyst-Plugin-Session>=0.10:../../www/p5-Catalyst-Plugin-Session

# PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
