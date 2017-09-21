# $NetBSD: Makefile,v 1.1 2013/06/30 13:39:57 noud4 Exp $

DISTNAME=	Sys-MemInfo-0.99
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SC/SCRESTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~scresto/Sys-MemInfo/
COMMENT=	Perl 5 module for getting memory information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Sys/MemInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
