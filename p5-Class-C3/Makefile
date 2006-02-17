# $NetBSD: Makefile,v 1.1.1.1 2006/02/17 05:45:49 jgoamakf Exp $

DISTNAME=		Class-C3-0.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Class-C3/
COMMENT=		Pragma to use the C3 method resolution order algortihm

DEPENDS+=		p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/C3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
