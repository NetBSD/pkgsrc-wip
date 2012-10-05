# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:55 asau Exp $
#

DISTNAME=	phantomjs-1.4.1-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	www
MASTER_SITES=	http://phantomjs.googlecode.com/files/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.phantomjs.org/
COMMENT=	Headless WebKit with JavaScript API
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/phantomjs-1.4.1
USE_LANGUAGES=	c c++ c99

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${DESTDIR}${PREFIX}/bin/

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
