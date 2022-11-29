# $NetBSD: Makefile,v 1.16 2022/11/25 13:31:34 wiz Exp $

.include "../../wip/qt5-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt5-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

BUILD_DIRS=	Python
PY_PATCHPLIST=	yes

MAKE_FLAGS+=		TARGET=Qsci.la TARGETD=Qsci.la TARGETL=Qsci.la
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
LIBS+=			-lqscintilla2
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}\ ${LIBS:Q}

# Mumble, "USE_TOOLS+=qmake".
pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

do-build:
	cd ${WRKSRC}/Python && ${CP} pyproject-qt5.toml pyproject.toml && sip-install

DEPENDS+=       ${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder

.include "../../lang/python/wheel.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/py-sip5/buildlink3.mk"
.include "../../wip/py-qt5/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=${PKGVERSION_NOREV}
.include "../../wip/qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
