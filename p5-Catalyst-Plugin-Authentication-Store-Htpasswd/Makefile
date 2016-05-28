# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Plugin-Authentication-Store-Htpasswd-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NU/NUFFIN/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-Store-Htpasswd/
COMMENT=	Use .htpasswd with Catalyst

DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.01:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Authen-Htpasswd>=0.13:../../security/p5-Authen-Htpasswd


PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/Store/Htpasswd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
