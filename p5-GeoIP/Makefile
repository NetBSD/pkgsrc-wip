# $NetBSD: Makefile,v 1.2 2003/06/01 10:31:10 jmmv Exp $
#

DISTNAME=	Geo-IP-1.15
PKGNAME=	p5-GeoIP-1.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://maxmind.com/geoip/api/perl.shtml
COMMENT=	Gets country name by IP or hostname

USE_BUILDLINK2=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geo/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/GeoIP/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
