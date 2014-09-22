# $NetBSD: Makefile,v 1.2 2014/09/22 07:43:06 makoto Exp $

DISTNAME=	PyQwt-5.2.0
CATEGORIES=	x11
MASTER_SITES=	http://prdownloads.sourceforge.net/pyqwt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyqwt.sourceforge.net/
COMMENT=	Set of Python bindings for the Qwt C++ class library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

.if 0
# qt3-libs or qt5-libs may seem to provide qfile.h but qt4-libs not:
# x11/qt5-qtbase/PLIST:qt5/include/QtCore/qfile.h
# See also TODO, thanks
#
BROKEN=	qwt_version_info.cpp:1:19: fatal error: qfile.h: No such file or directory
.endif

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
DEPENDS+=	qwt-[0-9]*:../../x11/qwt
GNU_CONFIGURE=	yes
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

do-configure:
	(cd ${WRKSRC}/configure ;\
	 python configure.py -Q ../qwt-5.2)

do-build:
	(cd ${WRKSRC}/configure ; ${GMAKE})

do-install:
	(cd ${WRKSRC}/configure ; \
	${GMAKE} DESTDIR=${DESTDIR} install)

.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"

.include "../../x11/qwt-qt4/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
