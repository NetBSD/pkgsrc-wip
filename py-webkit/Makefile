# $NetBSD: Makefile,v 1.11 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	pywebkitgtk-1.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pywebkitgtk.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pywebkitgtk/
COMMENT=	Python bindings for the WebKit GTK+
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PY_PATCHPLIST=		yes

PKGCONFIG_OVERRIDE+=	pywebkitgtk.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.13.0
.include "../../x11/py-gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
