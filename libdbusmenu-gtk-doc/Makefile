# $NetBSD: Makefile,v 1.3 2015/04/10 12:42:12 krytarowski Exp $

.include "../../wip/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gtk-doc-/}
COMMENT=	GTK+ API library documentation for libdbusmenu

DESCR_SRC+=	${.CURDIR}/DESCR

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--with-gtk=2
CONFIGURE_ARGS+=	--disable-dumper
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-vala
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		HAVE_VALGRIND_TRUE=
CONFIGURE_ENV+=		HAVE_VALGRIND_FALSE='\#'

NO_BUILD=	yes

INSTALL_DIRS=	docs/libdbusmenu-gtk

BUILDLINK_DEPMETHOD.glib2=	build
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
