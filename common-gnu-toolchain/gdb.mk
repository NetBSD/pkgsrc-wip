# $NetBSD$

DISTNAME=	gdb-16.3
PKGNAME=	cross-${TARGET}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	# empty
LICENSE=	gnu-gpl-v3

TARGET_PREFIX=	${PREFIX}/cross-${TARGET}

USE_TOOLS+=	bash:run gmake makeinfo
USE_LANGUAGES=	c c++
TOOLS_BROKEN+=	perl # used in do-install for texi2pod
GNU_CONFIGURE=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${TARGET_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=${TARGET}
INFO_FILES=		yes

REPLACE_BASH+=		gdb/gstack-1.in

# Uses all kinds of bashisms but is only needed for testing.
# If ever necessary, this should be fixed using REPLACE_BASH.
CHECK_PORTABILITY_SKIP+=	sim/testsuite/sim/bfin/run-tests.sh

DISTINFO_FILE?=	${.CURDIR}/../../wip/common-gnu-toolchain/distinfo-${DISTNAME}
PATCHDIR?=	${.CURDIR}/../../wip/common-gnu-toolchain/patches-${DISTNAME}

.include "gdb-options.mk"
.include "../../mk/bsd.prefs.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${TARGET_PREFIX}/info/bfd.info
	${RM} ${DESTDIR}${TARGET_PREFIX}/info/ctf-spec.info
	${RM} ${DESTDIR}${TARGET_PREFIX}/info/sframe-spec.info

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
