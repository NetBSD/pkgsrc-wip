# $NetBSD: Makefile,v 1.3 2004/02/20 20:45:06 tvierling Exp $
#

DISTNAME=		Class-MethodMaker-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MethodMaker/
COMMENT=		Getter/setter OO method maker for class elements

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class-MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
