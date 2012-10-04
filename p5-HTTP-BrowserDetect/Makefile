# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:29 asau Exp $

DISTNAME=		HTTP-BrowserDetect-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hbd
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTTP-BrowserDetect/
COMMENT=		Detect browser, version, OS from UserAgent

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTTP/BrowserDetect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
