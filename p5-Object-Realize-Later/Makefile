# $NetBSD: Makefile,v 1.2 2004/02/17 02:56:01 minskim Exp $

DISTNAME=	Object-Realize-Later-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/dist/Object-Realize-Later/
COMMENT=	Delayed creation of objects

DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
