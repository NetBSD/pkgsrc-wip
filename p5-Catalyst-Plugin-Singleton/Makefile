# $NetBSD: Makefile,v 1.1.1.1 2005/08/29 21:27:16 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Singleton-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Singleton
COMMENT=	Singleton to context.

PERL5_REQD+=    5.7.3

DEPENDS+=	p5-Catalyst>=0:../../www/p5-Catalyst
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

BUILDING_MODULE_BUILD=  yes
PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= 	auto/Catalyst/Plugin/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
