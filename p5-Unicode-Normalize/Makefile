# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 02:31:28 philnelson Exp $

DISTNAME=		Unicode-Normalize-1.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~sadahiro/Unicode-Normalize-1.02
COMMENT=		Unicode Normalization Froms

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST= auto/Unicode/Normalize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
