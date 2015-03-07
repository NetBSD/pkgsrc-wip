# $NetBSD: Makefile,v 1.3 2015/03/07 16:28:33 tnn2 Exp $

DISTNAME=	${GH_PROJECT}-${GH_TAGNAME}
PKGNAME=	android-tools-adb-5.0.2
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core
GH_TAGNAME=	android-5.0.2_r1

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
.include "../../mk/bsd.pkg.mk"
