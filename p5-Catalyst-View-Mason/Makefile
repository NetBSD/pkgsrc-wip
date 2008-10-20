# $NetBSD: Makefile,v 1.4 2008/10/20 10:10:19 tonnerre Exp $

DISTNAME=	Catalyst-View-Mason-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Mason/
COMMENT=	HTML Mason view class for Catalyst

PERL5_REQD+=	5.8.1
DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-HTML-Mason>=0:../../www/p5-HTML-Mason

PERL5_MODULE_TYPE= Module::Build
PERL5_PACKLIST= auto/Catalyst/View/Mason/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
