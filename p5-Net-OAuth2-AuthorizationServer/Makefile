# $NetBSD: Makefile,v 1.139 2018/09/02 07:55:30 wiz Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Net-OAuth2-AuthorizationServer-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AWS/LEEJO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::OAuth2::AuthorizationServer
COMMENT=	Easier implementation of an OAuth2 Authorization Server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/OAuth2/AuthorizationServer/.packlist

DEPENDS+=	p5-CryptX-[0-9]*:../../security/p5-CryptX

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
