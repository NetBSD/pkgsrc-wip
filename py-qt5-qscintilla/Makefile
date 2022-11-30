# $NetBSD: Makefile,v 1.16 2022/11/25 13:31:34 wiz Exp $

.include "../../wip/qt5-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt5-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../wip/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../wip/py-qt-builder

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

WHEEL_NAME=	${DISTNAME:S/_src//}

post-extract:
	cd ${WRKSRC} && ${CP} pyproject-qt5.toml pyproject.toml

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../lang/python/wheel.mk"
.include "../../wip/py-qt5/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=${PKGVERSION_NOREV}
.include "../../wip/qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
