# $NetBSD: Makefile,v 1.2 2003/04/25 18:55:28 drochner Exp $
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

PYTHON_VERSION_REQD=	22

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"

.include "../../wip/py-ORBit/buildlink2.mk"
.include "../../wip/py-gtk2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
