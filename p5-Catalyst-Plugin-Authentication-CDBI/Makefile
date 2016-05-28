# $NetBSD: Makefile,v 1.5 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Plugin-Authentication-CDBI-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication-CDBI/
COMMENT=	CDBI Authentication for Catalyst

DEPENDS+=	p5-Catalyst-Plugin-Session-FastMmap>=0:../../wip/p5-Catalyst-Plugin-Session-FastMmap
DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Model-CDBI>=0:../../wip/p5-Catalyst-Model-CDBI


PERL5_PACKLIST= auto/Catalyst/Plugin/Authentication/CDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
