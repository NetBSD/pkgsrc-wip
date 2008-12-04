# $NetBSD: Makefile,v 1.6 2008/12/04 23:01:33 minskim Exp $
#

DISTNAME=	xcb-proto-1.2
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xcb-proto.pc.in

CONFIGURE_ENV+=		XMLLLINT=${BUILDLINK_PREFIX.libxml}/bin/xmllint
PYTHON_FOR_BUILD_ONLY=	yes
PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	21 23 24

.include "../../lang/python/extension.mk"
BUILDLINK_DEPMETHOD.libxml2?=	build
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
