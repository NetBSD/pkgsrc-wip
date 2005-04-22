# $NetBSD: Makefile,v 1.1.1.1 2005/04/22 02:24:03 jgoamakf Exp $

DISTNAME=		File-Slurp-9999.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fsl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/File-Slurp/
COMMENT=		Read/write/append files quickly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
