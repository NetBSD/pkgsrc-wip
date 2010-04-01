# $NetBSD: Makefile,v 1.1.1.1 2010/04/01 13:42:20 ryo-on Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.rasterbar.com/products/libtorrent/python_binding.html
COMMENT=	Python binding of rasterbar libtorrent library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	bindings/python

CONFIGURE_ARGS+=	--enable-python-binding

DISTINFO_FILE=	${.CURDIR}/../../wip/libtorrent-rasterbar/distinfo

#SUBST_CLASSES+=		gcc-opt
#SUBST_STAGE.gcc-opt=	pre-configure
#SUBST_MESSAGE.gcc-opt=	lower optimization
#SUBST_FILES.gcc-opt=	configure
#SUBST_SED.gcc-opt=	-e 's,-O2,,g'
##SUBST_SED.gcc-opt=	-e 's,-O2,-O,g'

.include "../../lang/python/extension.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../wip/libtorrent-rasterbar/buildlink3.mk"

.include "../../wip/libtorrent-rasterbar/Makefile.common"
