# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:30 asau Exp $

DISTNAME=	Catalyst-Plugin-HTML-Widget-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-HTML-Widget/
COMMENT=	HTML Widget And Validation Framework

DEPENDS+=	p5-Catalyst-Runtime>=5.5:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-HTML-Widget>=0:../../wip/p5-HTML-Widget


PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/HTML/Widget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
