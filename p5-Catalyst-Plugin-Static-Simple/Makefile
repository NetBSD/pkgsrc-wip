# $NetBSD: Makefile,v 1.1.1.1 2007/02/06 09:32:33 netcap Exp $

DISTNAME=	Catalyst-Plugin-Static-Simple-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Static/
COMMENT=	Serve static files with Catalyst

PERL5_REQD+=	5.8.0

DEPENDS+=	p5-Catalyst>=2.99:../../wip/p5-Catalyst
BUILD_DEPENDS+=	p5-Module-Build>=0.2:../../devel/p5-Module-Build

PERL5_PACKLIST= auto/Catalyst/Plugin/Static/Simple/.packlist
# PERL5_CONFIGURE_DIRS=	${WRKSRC}
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
