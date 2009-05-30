# $NetBSD: Makefile,v 1.2 2009/05/30 10:17:11 jihbed Exp $
#

DISTNAME=	pywebkitgtk-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	http://pywebkitgtk.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pywebkitgtk/
COMMENT=	Python bindings for the WebKit GTK+ port
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-libxslt-[0-9]*:../../textproc/py-libxslt

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED= 26 25 24

PKGCONFIG_OVERRIDE+=	pywebkitgtk.pc.in


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.13.0
.include "../../x11/py-gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
