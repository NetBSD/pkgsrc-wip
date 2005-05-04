# $NetBSD: Makefile,v 1.3 2005/05/04 01:13:27 jeremy-c-reed Exp $
#

PKGNAME=	x${DISTNAME}
COMMENT=	X11 interface for pdq printing subsystem

DEPENDS+=	pdq>=2.2.1nb1:../../wip/pdq

PKGMANDIR?=	man  # until this is in real pkgsrc

CONFIGURE_ARGS+=	--with-glib-prefix="${BUILDLINK_PREFIX.glib}"
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--disable-gtktest

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} xpdq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xpdq ${PREFIX}/bin/xpdq
	${INSTALL_MAN} ${WRKSRC}/doc/xpdq.1 ${PREFIX}/${PKGMANDIR}/man1/xpdq.1

.include "../../wip/pdq/Makefile.common"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
