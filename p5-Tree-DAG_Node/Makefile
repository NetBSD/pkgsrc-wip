# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 21:56:39 daprice Exp $
#

DISTNAME=		Tree-DAG_Node-1.04
PKGNAME=		p5-${DISTNAME}
WRKSRC=                 ${WRKDIR}/Tree-DAG_Node-1.04
CATEGORIES=		devel
MASTER_SITES=		http://cpan.org/authors/id/S/SB/SBURKE/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=               http://cpan.org/authors/id/S/SB/SBURKE/Tree-DAG_Node-1.04.readme
COMMENT=		Class for representing nodes in a tree

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tree/DAG_Node/.packlist

pre-build:
	cd ${WRKSRC}; perl Makefile.PL

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
