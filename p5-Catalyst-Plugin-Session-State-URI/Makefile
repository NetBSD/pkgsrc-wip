# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:30 asau Exp $

DISTNAME=	Catalyst-Plugin-Session-State-URI-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-URI/
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.06:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-HTML-TokeParser-Simple>=0:../../www/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-URI-Find>=0:../../www/p5-URI-Find


# PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/State/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
