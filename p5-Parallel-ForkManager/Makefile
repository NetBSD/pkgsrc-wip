# $NetBSD: Makefile,v 1.2 2004/04/26 14:43:45 adrian_p Exp $
#

DISTNAME=	Parallel-ForkManager-0.7.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~dlux/Parallel-ForkManager-0.7.5/
COMMENT=	Simple parallel processing fork manager

NO_BUILDLINK=	YES

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parallel/ForkManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
