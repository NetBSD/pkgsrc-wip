# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:33 asau Exp $

DISTNAME=	Class-Date-1.1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cld
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Date/
COMMENT=	Perl class for easy date and time manipulation
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
