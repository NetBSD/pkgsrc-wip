# $NetBSD: Makefile,v 1.1.1.1 2005/07/18 19:55:09 kuli0020 Exp $

DISTNAME=	Class-ISA-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-ISA/
COMMENT=	Report the search path for a class's ISA tree

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Class/ISA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
