# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	easyjour-0.0.4
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://easyjour.rubyforge.org/
COMMENT=	Simple access to service announcing and discovery using Bonjour
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dnssd>=0.7.0:../../wip/ruby-dnssd

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
