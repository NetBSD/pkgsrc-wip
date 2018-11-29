# $NetBSD: Makefile,v 1.139 2018/09/02 07:55:30 wiz Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Mojolicious-Plugin-OAuth2-Server-0.42
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mojolicio.us/
COMMENT=	OAuth2 Authorization Server with Mojolicious
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojolicious/Plugin/OAuth2/Server/.packlist

DEPENDS+=	p5-Net-OAuth2-AuthorizationServer-[0-9]*:../../wip/p5-Net-OAuth2-AuthorizationServer

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
