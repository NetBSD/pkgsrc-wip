# $NetBSD: Makefile,v 1.71 2019/03/20 05:43:20 adam Exp $

DISTNAME=	libgpg-error-1.36
CATEGORIES=	security
ABI=		32
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/
MASTER_SITES+=	ftp://ftp.ring.gr.jp/pub/net/gnupg/libgpg-error/
EXTRACT_SUFX=	.tar.bz2

PKGNAME=	compat${ABI}_${DISTNAME}
MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/emul/netbsd32/
#CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/emul/netbsd32/share/
#CONFIGURE_ARGS+=	--localedir=${PREFIX}/emul/netbsd32/share/
INFO_FILES=		yes
TEST_TARGET=		check

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile+=	Makefile
SUBST_FILES.makefile+=	m4/Makefile
SUBST_FILES.makefile+=	tests/Makefile
SUBST_FILES.makefile+=	lang/cl/Makefile
SUBST_FILES.makefile+=	lang/Makefile
SUBST_FILES.makefile+=	doc/Makefile
SUBST_FILES.makefile+=	src/Makefile
SUBST_FILES.makefile+=	po/Makefile
SUBST_SED.makefile=	-e 's, /usr/pkg/share/locale,${PREFIX}/emul/netbsd32/share/locale,g'

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
LIBS+=	-lrt
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
