# $NetBSD: Makefile,v 1.1 2015/02/28 18:09:32 tnn2 Exp $

DISTNAME=	android-5.0.2_r1
PKGNAME=	android-tools-adb-5.0.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/android/platform_system_core/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.android.com/tools/help/adb.html
COMMENT=	Android debug bridge command line tool
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/platform_system_core-android-5.0.2_r1/adb
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_JOBS_SAFE=	no

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0

INSTALLATION_DIRS+=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
