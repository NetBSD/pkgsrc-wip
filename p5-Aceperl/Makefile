# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 21:52:41 daprice Exp $
#

DISTNAME=		AcePerl-1.86
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://www.cpan.org/authors/id/L/LD/LDS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.cpan.org/authors/id/L/LD/LDS/
COMMENT=		Perl interface for the ACEDB object-oriented database

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Ace/.packlist

pre-build:
	cd ${WRKSRC}; perl Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
