# $NetBSD: Makefile,v 1.2 2004/12/08 16:05:43 imilh Exp $
#

DISTNAME=	Math-Random-0.67
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Math-Random/
COMMENT=	Random number generators

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Math/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
