# $NetBSD: Makefile,v 1.4 2015/03/07 21:39:40 tnn2 Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	android-tools-adb-5.0.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/android/
GITHUB_PROJECT=	platform_system_core
GITHUB_TAG=	android-5.0.2_r1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.android.com/tools/help/adb.html
COMMENT=	Android debug bridge command line tool
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/adb
USE_TOOLS+=	gmake

MAKE_JOBS_SAFE=	no

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0

INSTALLATION_DIRS+=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
