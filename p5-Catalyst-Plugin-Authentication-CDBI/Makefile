# $NetBSD: Makefile,v 1.3 2006/10/30 22:45:31 shattered Exp $

DISTNAME=	Catalyst-Plugin-Authentication-CDBI-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-CDBI/
COMMENT=	CDBI Authentication for Catalyst

DEPENDS+=	p5-Catalyst-Plugin-Session-FastMmap>=0:../../wip/p5-Catalyst-Plugin-Session-FastMmap
DEPENDS+=	p5-Catalyst>=2.99:../../wip/p5-Catalyst
DEPENDS+=	p5-Catalyst-Model-CDBI>=0:../../wip/p5-Catalyst-Model-CDBI

PERL5_PACKLIST= auto/Catalyst/Plugin/Authentication/CDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
