# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:26 asau Exp $

DISTNAME=		Devel-Profiler-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dpr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Devel-Profiler/
COMMENT=		Perl profiler compatible with dprofpp

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Devel/Profiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
