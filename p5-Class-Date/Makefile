# $NetBSD: Makefile,v 1.3 2005/07/26 05:58:12 jgoamakf Exp $

DISTNAME=	Class-Date-1.1.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cld
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Date/
COMMENT=	Perl class for easy date and time manipulation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
