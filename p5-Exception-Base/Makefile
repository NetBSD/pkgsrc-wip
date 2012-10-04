# $NetBSD: Makefile,v 1.3 2012/10/04 10:45:27 asau Exp $

PKGVERSION=	0.13
DISTNAME=	Exception-Base-${PKGVERSION}
PKGNAME=	p5-Exception-Base-${PKGVERSION}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DE/DEXTER/}

MAINTAINER=	ggm@apnic.net
HOMEPAGE=	http://search.cpan.org/src/DEXTER/Exception-Base-0.13
COMMENT=	Exception::Base

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Exception/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
