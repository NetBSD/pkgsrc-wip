# $NetBSD: Makefile,v 1.1 2014/02/19 04:13:22 jgoamakf Exp $
#

DISTNAME=	WebService-GData-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SZ/SZABGAB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WebService-GData
COMMENT=	Google data protocol v2
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	p5-JSON>=2:../../converters/p5-JSON
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
BUILD_DEPENDS+=	p5-Test-Mock-LWP>=0.05:../../devel/p5-Test-Mock-LWP

PERL5_PACKLIST=		auto/WebService/GData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
