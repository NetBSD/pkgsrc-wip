# $NetBSD: Makefile,v 1.17 2015/06/12 10:50:47 wiz Exp $

DISTNAME=		Google-API-Client-0.14
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHIGETA/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/comewalk/google-api-perl-client
COMMENT=		Perl module for accessing Google APIs
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-libwww>0:../../www/p5-libwww
DEPENDS+=		p5-LWP-Protocol-https>0:../../www/p5-LWP-Protocol-https
DEPENDS+=		p5-URI>0:../../www/p5-URI
DEPENDS+=		p5-JSON-XS>0:../../converters/p5-JSON-XS
DEPENDS+=		p5-JSON-WebToken>0:../../wip/p5-JSON-WebToken

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Google/API/Client/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
