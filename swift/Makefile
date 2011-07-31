# $NetBSD: Makefile,v 1.1.1.1 2011/07/31 22:28:23 schnoebe Exp $
#

DISTNAME=	swift-1.0
CATEGORIES=	wip chat
MASTER_SITES=	http://www.swift.im/downloads/releases/swift-1.0/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.swift.im/
COMMENT=	Swift XMPP Client
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scons>=1.3:../../devel/scons

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_ACCEPTED=	26 27 31

# MAKE_ENV+= CPPPATH="${BUILDLINK_DIR}/include:${BUILDLINK_DIR}/qt4/include"
# MAKE_ENV+= LIBPATH="${BUILDLINK_DIR}/lib:${BUILDLINK_DIR}/qt4/lib"

do-configure:
	cd ${WRKSRC} ; \
	echo "qt=\"${QTDIR}\"" > config.py ;\
	echo "linkflags=\"-Wl,-R${QTDIR}/lib -Wl,-R${X11BASE}/lib -Wl,-R${BUILDLINK_DIR}/lib\"" >> config.py ; \
	echo "allow_warnings=\"true\"" >> config.py ;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
	    SWIFT_INSTALLDIR=${DESTDIR}/${PREFIX} ${DESTDIR}/${PREFIX} 

.include "../../lang/python/application.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
