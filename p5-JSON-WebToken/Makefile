# $NetBSD: Makefile,v 1.26 2015/06/12 10:48:32 wiz Exp $

DISTNAME=	JSON-WebToken-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5 
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-WebToken/
COMMENT=	JSON Web Token (JWT) implementation for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Crypt-OpenSSL-RSA>0:../../security/p5-Crypt-OpenSSL-RSA

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/JSON/WebToken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
