# $NetBSD: Makefile,v 1.4 2006/01/23 07:20:28 jgoamakf Exp $

DISTNAME=	HTTP-Server-Simple-0.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hss
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple/
COMMENT=	Simple standalone http dameon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTTP/Server/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
