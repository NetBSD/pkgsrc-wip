# $NetBSD: Makefile,v 1.6 2015/07/13 15:15:11 thomasklausner Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.rasterbar.com/products/libtorrent/python_binding.html
COMMENT=	Python binding of rasterbar libtorrent library

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	bindings/python

#CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_LIBS.py-boost}
CONFIGURE_ARGS+=	--with-boost-python
CONFIGURE_ARGS+=	--enable-python-binding

PATCHDIR=	${.CURDIR}/../../net/libtorrent-rasterbar/patches
DISTINFO_FILE=	${.CURDIR}/../../net/libtorrent-rasterbar/distinfo

.include "../../lang/python/extension.mk"
.include "../../devel/py-boost/buildlink3.mk"
.include "../../net/libtorrent-rasterbar/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
