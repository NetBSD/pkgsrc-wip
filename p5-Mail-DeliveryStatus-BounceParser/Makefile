# $NetBSD: Makefile,v 1.1 2012/12/03 18:54:29 othyro Exp $
#

DISTNAME=	Mail-DeliveryStatus-BounceParser-1.532
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mstevens/Mail-DeliveryStatus-BounceParser-1.532/lib/Mail/DeliveryStatus/BounceParser.pm
COMMENT=	Perl extension to analyze bounce messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-tools>=5.418:../../mail/p5-MIME-tools

USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
