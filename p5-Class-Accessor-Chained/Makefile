# $NetBSD: Makefile,v 1.1.1.1 2005/07/27 17:44:47 kuli0020 Exp $

DISTNAME=	Class-Accessor-Chained-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Chained
COMMENT=	make chained accessors

BUILD_DEPENDS=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL_MODBUILD=	yes

PERL5_PACKLIST= auto/Class/Accessor/Chained/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
