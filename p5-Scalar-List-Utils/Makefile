# $NetBSD: Makefile,v 1.2 2003/12/30 19:56:11 cjep Exp $
#

DISTNAME=		Scalar-List-Utils-1.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5slu
CATEGORIES=		lang perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/search?dist=Scalar-List-Utils
COMMENT=		Perl subroutines that would be nice to have in the perl core

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
