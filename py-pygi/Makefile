# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=	pygi-0.5.1
PKGNAME= ${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.gnome.org/Public/gnome/sources/pygi/0.5/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/PyGI
COMMENT=	Python dynamic bindings based on GObject-Introspection
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	gobject-introspection>=0.6.9:../../wip/gobject-introspection

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+= pkg-config

PYTHON_VERSIONS_ACCEPTED= 26 25
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
PY_PATCHPLIST=		yes

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.10.1nb1
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+=	libffi>=1.20
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
