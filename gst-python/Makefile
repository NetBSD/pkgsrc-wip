# $NetBSD: Makefile,v 1.2 2006/07/07 18:13:16 shattered Exp $
#

DISTNAME=		gst-python-0.10.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio devel
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-python/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://gstreamer.freedesktop.org/bindings/
COMMENT=		Python bindings for GStreamer

DEPENDS+=		${PYPKGPREFIX}-libxml2>=0.0:../../textproc/py-libxml2

PYTHON_VERSIONS_ACCEPTED=	23 24 25
PY_PATCHPLIST=		YES
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gst-python.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
MAKE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
