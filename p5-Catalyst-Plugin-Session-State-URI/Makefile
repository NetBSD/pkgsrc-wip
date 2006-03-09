# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 18:02:38 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Session-State-URI-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-URI/
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.01:../../wip/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-HTML-TokeParser-Simple>=0:../../wip/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/State/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
