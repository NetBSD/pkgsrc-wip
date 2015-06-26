# $NetBSD: Makefile,v 1.2 2015/06/26 22:26:57 othyro Exp $

DISTNAME=	Lingua-EN-Syllable-0.251
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gregfast/Lingua-EN-Syllable-0.251/
COMMENT=	Routine for estimating syllable count in words
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/EN/Syllable/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
