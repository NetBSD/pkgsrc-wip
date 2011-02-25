# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:48 thomasklausner Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.rasterbar.com/products/libtorrent/python_binding.html
COMMENT=	Python binding of rasterbar libtorrent library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27 26 25 24
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	bindings/python

#CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_LIBS.boost-python}
CONFIGURE_ARGS+=	--with-boost-python
CONFIGURE_ARGS+=	--enable-python-binding

PATCHDIR=	${.CURDIR}/../../wip/libtorrent-rasterbar/patches
DISTINFO_FILE=	${.CURDIR}/../../wip/libtorrent-rasterbar/distinfo

pre-patch:
	echo ${BUILDLINK_LIBS.boost-python}

.include "../../lang/python/extension.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../wip/libtorrent-rasterbar/buildlink3.mk"

.include "../../wip/libtorrent-rasterbar/Makefile.common"
