# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=		Cache-Mmap-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/Cache-Mmap
COMMENT=		Shared data cache using memory mapped files
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Cache/Mmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
