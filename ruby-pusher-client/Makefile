# $NetBSD$

DISTNAME=	pusher-client-0.6.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pusher/pusher-ruby-client
COMMENT=	Ruby WebSocket client for Pusher Channels
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-json-[0-9]*:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-websocket>=1.0:../../www/ruby-websocket

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
