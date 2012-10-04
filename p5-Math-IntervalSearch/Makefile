# $NetBSD: Makefile,v 1.4 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Math-Interpolate-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	This module contains several useful routines for interpolating data sets

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Math/Interpolate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
