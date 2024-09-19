# $NetBSD: options.mk,v 1.2 2013/12/24 13:36:25 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gambatte-dev
PKG_SUPPORTED_OPTIONS=	qt

.include "../../mk/bsd.options.mk"

PLIST_VARS=	qt

.if !empty(PKG_OPTIONS:Mqt)
# does not work well without GL:
# Xlib:  extension "GLX" missing on display ":0.0".
# QGLContext::makeCurrent(): Cannot make invalid context current.
# Segmentation fault (core dumped)
PLIST.qt=	yes

post-build:
	cd ${WRKSRC}/gambatte_qt && \
		${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake && \
		${SETENV} ${MAKE_ENV} ${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gambatte_qt/bin/gambatte_qt \
		${DESTDIR}${PREFIX}/bin

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif
