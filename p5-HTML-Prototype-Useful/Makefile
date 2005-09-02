# $NetBSD: Makefile,v 1.3 2005/09/02 18:21:00 kuli0020 Exp $

DISTNAME=	HTML-Prototype-Useful-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTML-Prototype-Useful
COMMENT=	Some useful additions for the Prototype library.

DEPENDS+=	p5-HTML-Prototype>=1.32:../../wip/p5-HTML-Prototype

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/HTML/Prototype/Useful/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
