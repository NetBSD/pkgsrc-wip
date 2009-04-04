# $NetBSD: Makefile,v 1.1.1.1 2009/04/04 14:48:17 jihbed Exp $
#

DISTNAME=	pywebkitgtk-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www
MASTER_SITES=	http://pywebkitgtk.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pywebkitgtk/
COMMENT=	Python bindings for the WebKit GTK+ port

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED= 25 24


PKGCONFIG_OVERRIDE+=	pywebkitgtk.pc.in

BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.13.0
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3

.include "../../lang/python/extension.mk"

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
