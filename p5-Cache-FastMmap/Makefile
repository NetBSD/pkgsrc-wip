# $NetBSD: Makefile,v 1.1.1.1 2005/08/05 02:55:30 jgoamakf Exp $

DISTNAME=		Cache-FastMmap-1.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cfm
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Cache-FastMmap/
COMMENT=		Shared memory cache through an mmap'ed file

PERL5_PACKLIST=		auto/Cache/FastMmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
