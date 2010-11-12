# $NetBSD: Makefile,v 1.2 2010/11/12 21:43:03 ryo-on Exp $

DISTNAME=		Data-Random-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~adeo/Data-Random-0.05
COMMENT=		Perl module to generate random data

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-Date-Calc>=5.4:../../devel/p5-Date-Calc

PERL5_PACKLIST=	auto/Data/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
