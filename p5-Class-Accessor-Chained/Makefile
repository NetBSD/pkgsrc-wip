# $NetBSD: Makefile,v 1.3 2006/05/19 16:51:28 ykomatsu Exp $

DISTNAME=	Class-Accessor-Chained-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Chained
COMMENT=	make chained accessors

DEPENDS=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL_MODBUILD=	yes

PERL5_PACKLIST= auto/Class/Accessor/Chained/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
