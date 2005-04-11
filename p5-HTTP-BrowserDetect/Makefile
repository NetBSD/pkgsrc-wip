# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:39 tvierling Exp $

DISTNAME=		HTTP-BrowserDetect-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hbd
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTTP-BrowserDetect/
COMMENT=		Detect browser, version, OS from UserAgent

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/BrowserDetect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
