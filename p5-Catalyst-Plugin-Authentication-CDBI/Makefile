# $NetBSD: Makefile,v 1.1.1.1 2005/08/26 19:50:54 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Authentication-CDBI-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-CDBI/
COMMENT=	Catalyst::Plugin::Authentication::CDBI - CDBI Authentication for Catalyst

DEPENDS+=	p5-Catalyst-Plugin-Session-FastMmap>=0:../../www/p5-Catalyst-Plugin-Session-FastMmap
DEPENDS+=	p5-Catalyst>=2.99:../../www/p5-Catalyst
DEPENDS+=	p5-Catalyst-Model-CDBI>=0:../../www/p5-Catalyst-Model-CDBI

PERL5_PACKLIST= auto/Catalyst/Plugin/Authentication/CDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
