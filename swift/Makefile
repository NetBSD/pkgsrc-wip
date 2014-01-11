# $NetBSD: Makefile,v 1.6 2014/01/11 15:27:23 thomasklausner Exp $

DISTNAME=	swift-2.0
CATEGORIES=	chat
MASTER_SITES=	http://swift.im/downloads/releases/swift-2.0/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://swift.im/
COMMENT=	Swift XMPP Client
LICENSE=	gnu-gpl-v3

DEPENDS+=	scons>=1.3:../../devel/scons

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# MAKE_ENV+= CPPPATH="${BUILDLINK_DIR}/include:${BUILDLINK_DIR}/qt4/include"
# MAKE_ENV+= LIBPATH="${BUILDLINK_DIR}/lib:${BUILDLINK_DIR}/qt4/lib"

do-configure:
	cd ${WRKSRC} ; \
	${ECHO} "qt=\"${QTDIR}\"" > config.py ;\
	${ECHO} "linkflags=\"-Wl,-R${QTDIR}/lib -Wl,-R${X11BASE}/lib -Wl,-R${BUILDLINK_DIR}/lib\"" >> config.py ; \
	${ECHO} "allow_warnings=\"true\"" >> config.py ;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
	    SWIFT_INSTALLDIR=${DESTDIR}/${PREFIX} ${DESTDIR}/${PREFIX}

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
