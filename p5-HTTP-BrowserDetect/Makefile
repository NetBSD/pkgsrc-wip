# $NetBSD: Makefile,v 1.5 2013/04/19 04:39:17 jgoamakf Exp $

DISTNAME=		HTTP-BrowserDetect-1.50
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/HTTP-BrowserDetect/
COMMENT=		Detect browser, version, OS from UserAgent
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=		auto/HTTP/BrowserDetect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
