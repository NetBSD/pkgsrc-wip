# $NetBSD: Makefile,v 1.1.1.1 2005/08/22 19:29:00 kuli0020 Exp $

DISTNAME=	HTML-TagCloud-0.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-TagCloud/
COMMENT=	Generate An HTML Tag Cloud

DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple

BUILDING_MODULE_BUILD=  yes
PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/HTML/TagCloud/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
