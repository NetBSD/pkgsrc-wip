# $NetBSD: Makefile,v 1.7 2013/04/18 01:00:08 jgoamakf Exp $

DISTNAME=	HTML-TagCloud-0.38
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-TagCloud/
COMMENT=	Generate An HTML Tag Cloud
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/HTML/TagCloud/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
