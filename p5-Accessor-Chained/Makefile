# $NetBSD: Makefile,v 1.2 2006/01/26 03:14:33 jgoamakf Exp $

DISTNAME=	Class-Accessor-Chained-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Chained
COMMENT=	Make chained accessors

BUILD_DEPENDS=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL_MODBUILD=	yes

PERL5_PACKLIST= auto/Class/Accessor/Chained/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
