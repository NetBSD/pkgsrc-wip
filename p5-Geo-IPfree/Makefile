# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:38 tvierling Exp $
#

DISTNAME=	Geo-IPfree-0.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~gmpassos/Geo-IPfree-0.2/
COMMENT=	Gets country name by IP or hostname

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
