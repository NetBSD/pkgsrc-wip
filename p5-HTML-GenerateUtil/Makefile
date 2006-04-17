# $NetBSD: Makefile,v 1.1.1.1 2006/04/17 09:09:51 jgoamakf Exp $

DISTNAME=		HTML-GenerateUtil-1.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTML-GenerateUtil/
COMMENT=		Routines useful when generating HTML output

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/GenerateUtil/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
