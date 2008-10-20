# $NetBSD: Makefile,v 1.3 2008/10/20 10:10:18 tonnerre Exp $

DISTNAME=	Catalyst-Plugin-ConfigLoader-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-ConfigLoader/
COMMENT=	Load Catalyst config from YAML file

PERL5_REQD+=	5.8.0

DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Config-Any>=0.04:../../devel/p5-Config-Any
BUILD_DEPENDS+=	p5-Module-Build>=0.2:../../devel/p5-Module-Build

PERL5_PACKLIST= auto/Catalyst/Plugin/ConfigLoader/.packlist
# PERL5_CONFIGURE_DIRS=	${WRKSRC}
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
