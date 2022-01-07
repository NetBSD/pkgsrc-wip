# $NetBSD$

DISTNAME=	PyQtWebEngine-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-qt5-webengine-5.15.5
CATEGORIES=	x11 python
# MASTER_SITES=	${MASTER_SITE_PYPI:=p/PyQtWebEngine/}
MASTER_SITES=	https://files.pythonhosted.org/packages/60/66/56e118abb4cddd8e4bea6f89bdec834069b52479fb991748f1b21950811e/
# https://files.pythonhosted.org/packages/60/66/56e118abb4cddd8e4bea6f89bdec834069b52479fb991748f1b21950811e/PyQtWebEngine-5.15.5.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/PyQtWebEngine
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqtwebengine/
COMMENT=	Python module for QtWebEngine (Chromium-based)
LICENSE=	gnu-gpl-v3

.include "../../lang/python/pyversion.mk"

USE_LANGUAGES=	c c++
USE_LIBTOOL=            yes
USE_TOOLS+=             gmake pkg-config

CONFIGURE_ARGS+=        -d ${PREFIX}/${PYSITELIB}/PyQt5
CONFIGURE_ARGS+=        --pyqt-sipdir ${PREFIX}/share/sip${PYVERSSUFFIX}/PyQt5
CONFIGURE_ARGS+=        -q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=        --sip ${BUILDLINK_PREFIX.py-sip}/bin/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--apidir ${PREFIX}/qt5/qsci${PYVERSSUFFIX}
CONFIGURE_ARGS+=        --verbose

PY_PATCHPLIST=		yes

INSTALL_ENV+=           INSTALL_ROOT=${DESTDIR}

.if ${_PYTHON_VERSION} == 27
#DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif
DEPENDS+=       ${PYPKGPREFIX}-sip-qt5>=4.19.23:../../x11/py-sip-qt5

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
                ${PYTHONBIN} configure.py ${CONFIGURE_ARGS}

#TODO hopefully there is a configure parameter for this?
#post-install:
#	cd ${PREFIX}${DESTDIR}/${PYSITELIB} && mv QtWebEngine*so PyQt5/

.include "../../mk/bsd.prefs.mk"

.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
