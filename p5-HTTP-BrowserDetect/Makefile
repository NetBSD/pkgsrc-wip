# $NetBSD: Makefile,v 1.3 2005/07/26 05:58:13 jgoamakf Exp $

DISTNAME=		HTTP-BrowserDetect-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hbd
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTTP-BrowserDetect/
COMMENT=		Detect browser, version, OS from UserAgent

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTTP/BrowserDetect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
