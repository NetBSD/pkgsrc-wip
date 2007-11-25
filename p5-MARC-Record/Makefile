# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 02:49:44 philnelson Exp $

DISTNAME=		MARC-Record-2.0.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~mikery/MARC-Record-2.0.0
COMMENT=		MARC record handling package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
