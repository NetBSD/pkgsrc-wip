# $NetBSD: Makefile,v 1.2 2003/07/13 03:46:18 schnoebe Exp $
#

DISTNAME=	IO-Tee-0.64
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ite
CATEGORIES=	wip devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=IO::Tee
COMMENT=	Multiplex output to multiple output handles

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Tee/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
