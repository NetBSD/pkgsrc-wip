# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Math-Interpolate-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	Contains several useful routines for interpolating data sets

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Math/Interpolate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
