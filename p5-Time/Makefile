# $NetBSD: Makefile,v 1.2 2003/04/06 19:14:55 jmmv Exp $
#

DISTNAME=	Time-modules-101.062101
PKGNAME=	${DISTNAME:S/Time-modules/p5-Time/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	jrp@hispabsd.org
#HOMEPAGE=	
COMMENT=	Collection of functions to convert and use time variables

USE_BUILDLINK2=		YES

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
