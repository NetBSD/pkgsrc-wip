# $NetBSD: Makefile,v 1.3 2005/09/02 17:08:20 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Singleton-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Singleton
COMMENT=	Singleton to context.

PERL5_REQD+=    5.7.3

DEPENDS+=	p5-Catalyst>=0:../../wip/p5-Catalyst
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= 	auto/Catalyst/Plugin/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
