# $NetBSD: Makefile,v 1.4 2012/10/04 19:12:05 asau Exp $

DISTNAME=	XML-DOM-XPath-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/XML-DOM-XPath/
COMMENT=	Helper module for XML::DOM that adds XPath support to it

DEPENDS+=	p5-XML-DOM>=1.43:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-XPath>=1.13:../../textproc/p5-XML-XPath

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/XML/DOM/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
