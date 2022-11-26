# $NetBSD: Makefile,v 1.16 2022/11/25 13:31:34 wiz Exp $

.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt5-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

WRKSRC=	${WRKDIR}/${DISTNAME}/Python
PY_PATCHPLIST=	yes

MAKE_FLAGS+=		TARGET=Qsci.la TARGETD=Qsci.la TARGETL=Qsci.la
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
LIBS+=			-lqscintilla2
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}\ ${LIBS:Q}

pre-configure:
	cd ${WRKSRC} && ${CP} pyproject-qt5.toml pyproject.toml

do-build:
	cd ${WRKSRC} && sip-install

.include "../../lang/python/wheel.mk"
.include "../../x11/py-sip5/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=${PKGVERSION_NOREV}
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
