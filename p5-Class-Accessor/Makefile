# $NetBSD: Makefile,v 1.1.1.1 2004/01/18 19:02:01 jgoamakf Exp $
#

DISTNAME=	Class-Accessor-0.18
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cac
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor/
COMMENT=	Automated accessor generation

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
