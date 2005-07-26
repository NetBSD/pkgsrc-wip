# $NetBSD: Makefile,v 1.3 2005/07/26 05:58:12 jgoamakf Exp $

DISTNAME=		Cache-Mmap-0.081
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cmm
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Cache-Mmap/
COMMENT=		Shared data cache using memory mapped files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Cache/Mmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
