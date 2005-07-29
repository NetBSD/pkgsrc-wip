# $NetBSD: Makefile,v 1.1.1.1 2005/07/29 02:11:03 jgoamakf Exp $

DISTNAME=		File-Path-Expand-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fpe
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/File-Path-Expand/
COMMENT=		Expands user directories in filenames

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File-Path-Expand/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
