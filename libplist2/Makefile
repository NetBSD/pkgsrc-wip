# $NetBSD$

DISTNAME=	libplist-${PKGVERSION_NOREV}
PKGNAME=	libplist2-2.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/libplist/releases/download/2.2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Handle Apple Binary and XML Property Lists
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash
USE_TOOLS+=	bash gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=		libplist++-2.0.pc.in
PKGCONFIG_OVERRIDE+=		libplist-2.0.pc.in
PY_PATCHPLIST=			yes

PYTHON_VERSIONS_ACCEPTED=	27

CONFLICTS+=	libplist-[0-9]*

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-cython/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
