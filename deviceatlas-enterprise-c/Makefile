# $NetBSD: Makefile,v 1.1 2015/07/07 13:21:28 devnexen Exp $

DISTNAME=	deviceatlas_c_${PKGVERSION}
EXTRACT_SUFX=	.zip
PKGNAME=	deviceatlas-enterprise-c
PKGVERSION=	0.9
PKGREVISION=	0
CATEGORIES=	net devel
MASTER_SITES=	manual

USE_LANGUAGES=	c c++

HOMEPAGE=	https://www.deviceatlas.com
COMMENT=	DeviceAtlas Device Detection C API
LICENSE=	deviceatlas-enterprise-c-license

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-${PKGVERSION}
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
	@cd ${WRKSRC} && cmake -DINSTALL_PREFIX=${LOCALBASE}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
