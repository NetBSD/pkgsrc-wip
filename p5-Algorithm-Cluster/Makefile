# $NetBSD: Makefile,v 1.3 2013/02/14 18:56:25 shattered Exp $
#

DISTNAME=	Algorithm-Cluster-1.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MD/MDEHOON/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Cluster/
COMMENT=	Perl interface to the C Clustering Library
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=		auto/Algorithm/Cluster/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
