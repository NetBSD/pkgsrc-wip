# $NetBSD: Makefile,v 1.1 2004/01/09 01:11:07 yeled Exp $

DISTNAME=		Net-Netmask-1.9007
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://cpan.org/modules/by-module/Net/
COMMENT=		Perl module for netmask lookups

#DEPENDS+=		p5-Class-Factory-Util-[0-9]*:../../wip/p5-Class-Factory-Util
#DEPENDS+=		p5-DateTime-LeapSecond-[0-9]*:../../wip/p5-DateTime-LeapSecond
#DEPENDS+=		p5-DateTime-TimeZone-[0-9]*:../../wip/p5-DateTime-TimeZone
#DEPENDS+=		p5-Params-Validate>=0.52:../../devel/p5-Params-Validate
#DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Netmask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
