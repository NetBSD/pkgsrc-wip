# $NetBSD: Makefile,v 1.1.1.1 2003/05/21 09:35:07 xtraeme Exp $
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

.include "../../wip/geoip/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
