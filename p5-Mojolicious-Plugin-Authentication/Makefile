# $NetBSD$

DISTNAME=	Mojolicious-Plugin-Authentication-1.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://metacpan.org/pod/Mojolicious::Plugin::Authentication
COMMENT=	Authentication plugin for the Mojolicious framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mojolicious>=8.0:../../www/p5-Mojolicious

PERL5_PACKLIST=	auto/Mojolicious/Plugin/Authentication/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
