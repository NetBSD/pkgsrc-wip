# $NetBSD: Makefile,v 1.3 2012/10/04 19:11:58 asau Exp $

DISTNAME=		Startup-0.103
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5stu
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unicode/MSCHWARTZ/}

MAINTAINER=		pkgsrc-p5-people@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Startup/
COMMENT=		Program flow utility

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Startup/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
