# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 06:36:21 bradv Exp $
#

DISTNAME=       File-Tail-0.98
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5fta
CATEGORIES=     devel perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=     bradv@affectation.org
COMMENT=        perl5 functions for monitoring continuously appended files

DEPENDS+=	p5-Time-HiRes:../../time/p5-Time-HiRes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
