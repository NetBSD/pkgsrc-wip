# $NetBSD: Makefile,v 1.1.1.1 2009/11/11 12:10:48 fhajny Exp $

DISTNAME=	nokogiri-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nokogiri.rubyforge.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=      gemspec

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
