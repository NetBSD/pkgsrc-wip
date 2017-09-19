# $NetBSD: Makefile,v 1.4 2015/03/07 21:39:40 tnn2 Exp $

MASTER_SITES=	https://github.com/android/
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	android-tools-adb-8.0.0.r11
CATEGORIES=	devel
GITHUB_PROJECT=	platform_system_core
GITHUB_TAG=	android-8.0.0_r11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.android.com/tools/help/adb.html
COMMENT=	Android debug bridge command line tool
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c gnu++14

#CPPFLAGS+=	-I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0

CPPFLAGS+=	-I${BUILDLINK_PREFIX.boringssl}/bssl/include
CPPFLAGS+=	-L${BUILDLINK_PREFIX.boringssl}/bssl

CFLAGS=-DADB_REVISION=${PKGNAME_NOREV}

INSTALLATION_DIRS+=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/adb-Makefile ${WRKSRC}/adb/Makefile
	${CP} ${FILESDIR}/adb-client-Makefile ${WRKSRC}/adb/client/Makefile
	${CP} ${FILESDIR}/libcutils-Makefile ${WRKSRC}/libcutils/Makefile
	${CP} ${FILESDIR}/base-Makefile ${WRKSRC}/base/Makefile
	${CP} ${FILESDIR}/stdatomic.h ${WRKSRC}/libcutils/include


.include "../../devel/libusb1/buildlink3.mk"
.include "../../wip/boringssl/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
