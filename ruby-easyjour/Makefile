# $NetBSD: Makefile,v 1.2 2010/09/14 07:33:46 obache Exp $
#

DISTNAME=	easyjour-0.0.4
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://easyjour.rubyforge.org/
COMMENT=	Simple access to service announcing and discovery using Bonjour
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dnssd>=0.7.0:../../wip/ruby-dnssd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
