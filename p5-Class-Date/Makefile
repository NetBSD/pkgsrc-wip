# $NetBSD: Makefile,v 1.1.1.1 2004/09/27 21:57:38 jgoamakf Exp $

DISTNAME=	Class-Date-1.1.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cld
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Date/
COMMENT=	Perl class for easy date and time manipulation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
