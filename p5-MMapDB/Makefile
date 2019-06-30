# $NetBSD: Makefile,v 1.3 2013/04/25 02:11:21 jgoamakf Exp $
#

DISTNAME=	MMapDB-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OP/OPI/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://metacpan.org/release/MMapDB
COMMENT=	Simple database in shared memory
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-File-Map>=0:../../wip/p5-File-Map

PERL5_PACKLIST=		auto/MMapDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
