# $NetBSD: Makefile,v 1.1.1.1 2005/01/29 17:15:43 jgoamakf Exp $

DISTNAME=		Devel-Profiler-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dpr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Devel-Profiler/
COMMENT=		Perl profiler compatible with dprofpp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Profiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
