# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 07:19:54 jeremy-c-reed Exp $
#

PKGNAME=	x${DISTNAME}
COMMENT=	X11 interface for pdq printing subsystem

DEPENDS+=	${DISTNAME}:../../wip/pdq

CONFIGURE_ARGS+=	--with-glib-prefix="${BUILDLINK_PREFIX.glib}"
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--disable-gtktest

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} xpdq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xpdq ${PREFIX}/bin/xpdq
	${INSTALL_MAN} ${WRKSRC}/doc/xpdq.1 ${PREFIX}/man/man1/xpdq.1

.include "../../wip/pdq/Makefile.common"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
