# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 13:51:27 obache Exp $
#

DISTNAME=	easyjour-0.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://easyjour.rubyforge.org/
COMMENT=	Simple access to service announcing and discovery using Bonjour
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dnssd>=0.7.0:../../wip/ruby-dnssd

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
