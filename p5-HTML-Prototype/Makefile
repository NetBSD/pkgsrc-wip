# $NetBSD: Makefile,v 1.1.1.1 2005/08/22 18:40:42 kuli0020 Exp $

DISTNAME=	HTML-Prototype-1.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-Prototype
COMMENT=	Generate HTML and Javascript for the Prototype library

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-HTML-Tree>=0:../../www/p5-HTML-Tree

BUILDING_MODULE_BUILD=  yes
PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/HTML/Prototype/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
