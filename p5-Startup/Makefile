# $NetBSD: Makefile,v 1.1.1.1 2008/07/01 13:51:07 tonnerre Exp $

DISTNAME=		Startup-0.103
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5stu
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unicode/MSCHWARTZ/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Startup/
COMMENT=		Program flow utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Startup/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
