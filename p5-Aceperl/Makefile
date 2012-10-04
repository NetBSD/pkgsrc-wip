# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:19 asau Exp $
#

DISTNAME=		AcePerl-1.86
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://www.cpan.org/authors/id/L/LD/LDS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.cpan.org/authors/id/L/LD/LDS/
COMMENT=		Perl interface for the ACEDB object-oriented database

PKG_DESTDIR_SUPPORT=    none

PERL5_PACKLIST=		auto/Ace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
