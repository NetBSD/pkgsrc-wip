# $NetBSD: Makefile,v 1.4 2003/06/03 21:02:31 marc Exp $
#

DISTNAME=	gnome-python-1.99.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-python-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSION_REQD=	22pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../net/py-ORBit/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
