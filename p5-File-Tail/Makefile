# $NetBSD: Makefile,v 1.5 2004/05/11 18:22:40 minskim Exp $
#

DISTNAME=       File-Tail-0.98
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5fta
CATEGORIES=     devel perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=     bradv@affectation.org
COMMENT=        Perl5 functions for monitoring continuously appended files

DEPENDS+=	p5-Time-HiRes>=1.49:../../time/p5-Time-HiRes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
