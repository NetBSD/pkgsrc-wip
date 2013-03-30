# $NetBSD: Makefile,v 1.3 2013/03/30 20:53:30 jgoamakf Exp $

DISTNAME=		HTML-GenerateUtil-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTML-GenerateUtil/
COMMENT=		Routines useful when generating HTML output
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/GenerateUtil/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
