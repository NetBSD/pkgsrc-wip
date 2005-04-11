# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:36 tvierling Exp $
#

DISTNAME=		AcePerl-1.86
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://www.cpan.org/authors/id/L/LD/LDS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.cpan.org/authors/id/L/LD/LDS/
COMMENT=		Perl interface for the ACEDB object-oriented database

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Ace/.packlist

pre-build:
	cd ${WRKSRC}; perl Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
