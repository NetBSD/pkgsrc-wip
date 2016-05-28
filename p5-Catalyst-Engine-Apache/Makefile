# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:27 asau Exp $

DISTNAME=	Catalyst-Engine-Apache-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AG/AGRUNDMA/}
PERL5_REQD+=	5.8.1

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Engine-Apache/
COMMENT=	Catalyst Apache Engines

BUILD_DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime


PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST= auto/Catalyst/Engine/Apache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
