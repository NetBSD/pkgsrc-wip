# $NetBSD: Makefile,v 1.5 2015/08/10 05:26:29 devnexen Exp $

EXTRACT_SUFX=	.zip
DISTNAME=	deviceatlas-enterprise-c-${API_VERSION}
API_VERSION=	2.1
PKGREVISION=	5
CATEGORIES=	net devel
MASTER_SITES=	#

USE_LANGUAGES=	c c++

HOMEPAGE=	https://www.deviceatlas.com/deviceatlas-haproxy-module
COMMENT=	DeviceAtlas Device Detection C API
LICENSE=	deviceatlas-enterprise-c-license

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	cmake

RESTRICTED=		License prohibits redistribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	lib include

FETCH_MESSAGE=  "Please fetch ${DISTFILES} manually from"
FETCH_MESSAGE+= "${HOMEPAGE}"
FETCH_MESSAGE+= "and put into"
FETCH_MESSAGE+= "${DISTDIR}"

pre-build:
	cd ${WRKSRC} && cmake -DINSTALL_PREFIX=${LOCALBASE}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
