# $NetBSD: Makefile,v 1.1.1.1 2004/01/28 15:26:49 jgoamakf Exp $
#

DISTNAME=	Class-Trigger-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ctr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Trigger/
COMMENT=	Mixin to add / call inheritable triggers

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Trigger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
