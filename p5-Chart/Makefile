# $NetBSD: Makefile,v 1.1.1.1 2003/04/05 14:45:14 adrian_p Exp $
#

DISTNAME=	Chart-1.0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/author/CHARTGRP/Chart-1.0.1/Chart.pod
COMMENT=	Perl5 charting library

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD

USE_BUILDLINK2=	YES

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Chart/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
