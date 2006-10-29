# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:50 shattered Exp $

DISTNAME=	Catalyst-View-Mason-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Mason/
COMMENT=	HTML Mason view class for Catalyst

PERL5_REQD+=	5.8.1
DEPENDS+=	p5-Catalyst>=5.50:../../wip/p5-Catalyst
DEPENDS+=	p5-Path-Class>=0:../../wip/p5-Path-Class
DEPENDS+=	p5-HTML-Mason>=0:../../www/p5-HTML-Mason

PERL5_MODULE_TYPE= Module::Build
PERL5_PACKLIST= auto/Catalyst/View/Mason/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
