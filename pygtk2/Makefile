# $NetBSD: Makefile,v 1.1.1.1 2003/03/25 19:00:42 marc Exp $
#

DISTNAME=	pygtk-1.99.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for GTK+2

CONFLICTS=	${PYPKGPREFIX}-gtk-*

PY_PATCHPLIST=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pygtk-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSION_REQD>=	22

.include "../../mk/pthread.buildlink2.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "native")
CONFIGURE_ARGS+=	--enable-thread
.endif

DOCDIR=	${PREFIX}/share/doc/pygtk
EGDIR=	${PREFIX}/share/examples/pygtk

PYTHON_PATCH_SCRIPTS=	examples/atk/*.py
PYTHON_PATCH_SCRIPTS+=	examples/gl/*.py
PYTHON_PATCH_SCRIPTS+=	examples/glade/*.py
PYTHON_PATCH_SCRIPTS+=	examples/gobject/*.py
PYTHON_PATCH_SCRIPTS+=	examples/ide/*.py
PYTHON_PATCH_SCRIPTS+=	examples/neil/*.py
PYTHON_PATCH_SCRIPTS+=	examples/pango/*.py
PYTHON_PATCH_SCRIPTS+=	examples/pygtk-demo/*.py
PYTHON_PATCH_SCRIPTS+=	examples/pygtk-demo/demos/*.py
PYTHON_PATCH_SCRIPTS+=	examples/simple/*.py

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	@cd ${WRKSRC}/examples && \
		${PAX} -rw * ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/THREADS ${DOCDIR}

.include "../../devel/libglade2/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../wip/gtkglarea2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
