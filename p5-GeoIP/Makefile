# $NetBSD: Makefile,v 1.5 2004/02/17 03:53:40 minskim Exp $
#

DISTNAME=	Geo-IP-1.15
PKGNAME=	p5-GeoIP-1.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/geoip/api/perl.shtml
COMMENT=	Gets country name by IP or hostname

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geo/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
