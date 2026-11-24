# $NetBSD$

DISTNAME=	guile-websocket-0.3.0
CATEGORIES=	net
MASTER_SITES=	https://files.dthompson.us/releases/guile-websocket/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://dthompson.dev/projects/guile-websocket.html
COMMENT=	Guile Scheme implementation of protocol as defined by RFC 6455
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS=	pkg-config gmake

DEPENDS+=	guile-gnutls>=3.7.11:../../wip/guile-gnutls
DEPENDS+=	guile-fibers>=2.0.0:../../wip/guile-fibers

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/guile/3.0

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
