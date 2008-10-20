# $NetBSD: Makefile,v 1.3 2008/10/20 10:10:19 tonnerre Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-Cookie/
COMMENT=	Stores a Catalyst Session in a Cookie

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.01:../../www/p5-Catalyst-Plugin-Session

# PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/State/Cookie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
