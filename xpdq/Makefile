# $NetBSD: Makefile,v 1.4 2009/03/18 13:04:38 cheusov Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xpdq ${DESTDIR}${PREFIX}/bin/xpdq
	${INSTALL_MAN} ${WRKSRC}/doc/xpdq.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpdq.1

.include "../../wip/pdq/Makefile.common"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
