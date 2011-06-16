# $NetBSD: Makefile,v 1.2 2011/06/16 03:08:54 makoto Exp $

PKGNAME=	ja-freewnn-lib-1.11alpha22

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

INSTALL_TARGET=		install install.man
# install.man
MAKE_ENV+=		"DESTDIR=${DESTDIR}"

post-install:
			(cd ${WRKSRC};	\
			env DESTDIR=${DESTDIR} ${MAKE} install.man )

.include "../../wip/ja-freewnn-lib/Makefile.common"
.include "../../mk/bsd.pkg.mk"
