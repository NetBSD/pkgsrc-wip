# $NetBSD: Makefile,v 1.1.1.1 2005/01/29 17:12:37 jgoamakf Exp $

DISTNAME=		Cache-Mmap-0.081
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cmm
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Cache-Mmap/
COMMENT=		Shared data cache using memory mapped files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Cache/Mmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
