# $NetBSD: Makefile,v 1.3 2012/10/04 19:11:58 asau Exp $

DISTNAME=	Pod-Constants-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MG/MGV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Constants/
COMMENT=	Include constants from POD
LICENSE=	artistic-2.0 # OR gnu-gpl-v2

DEPENDS+=	p5-Test-Simple>=0.18:../../devel/p5-Test-Simple
DEPENDS+=	p5-Pod-Parser>=1.13:../../textproc/p5-Pod-Parser

PERL5_PACKLIST=	auto/Pod/Constants/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
