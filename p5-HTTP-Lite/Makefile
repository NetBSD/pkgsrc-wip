# $NetBSD: Makefile,v 1.1.1.1 2005/06/18 01:24:35 schnoebe Exp $

DISTNAME=		HTTP-Lite-2.1.6
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hl
CATEGORIES=		www perl5 wip
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://search.cpan.org/dist/HTTP-Lite/
COMMENT=		Lightweight HTTP client implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
