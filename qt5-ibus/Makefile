# $NetBSD: Makefile,v 1.2 2015/01/01 07:06:06 nros Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-ibus-${QTVERSION}
COMMENT=	Qt5 IBus input context plugin

BUILD_DIRS=	src/plugins/platforminputcontexts/ibus

INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}
MAKE_ENV+=	QTDIR=${QTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

pre-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake -o Makefile

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
