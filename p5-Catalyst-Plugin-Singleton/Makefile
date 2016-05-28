# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:31 asau Exp $

DISTNAME=	Catalyst-Plugin-Singleton-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Singleton//
COMMENT=	Singleton to context

PERL5_REQD+=	5.7.3

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/Catalyst/Plugin/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
