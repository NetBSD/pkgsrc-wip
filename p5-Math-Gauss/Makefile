# $NetBSD: Makefile,v 1.1.1.1 2012/04/08 21:58:44 bubuchka Exp $

DISTNAME=	Math-Gauss-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Gauss/
COMMENT=	Perl module for Gaussian probability distribution

LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/Gauss/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
