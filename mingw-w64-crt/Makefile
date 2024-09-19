# $NetBSD: Makefile,v 1.5 2012/10/03 15:09:55 asau Exp $

DISTNAME=	mingw-w64-v2.0
PKGNAME=	mingw-w64-crt-2.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mingw-w64/mingw-w64/mingw-w64-release/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw-w64.sourceforge.net/
COMMENT=	C runtime for win32/64 cross-development
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=		mingw-w64-gcc-[0-9]*:../../wip/mingw-w64-gcc
DEPENDS+=		mingw-w64-headers-[0-9]*:../../wip/mingw-w64-headers

WRKSRC=			${WRKDIR}/${DISTNAME:S/-snapshot//}
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
USE_TOOLS+=		gmake

USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}	\
			--host=x86_64-w64-mingw32			\
			--enable-lib32

CONFIGURE_DIRS=		../build
BUILD_DIRS=		../build
INSTALL_DIRS=		../build

CONFIGURE_SCRIPT=	${WRKSRC}/mingw-w64-crt/configure

# bypass buildlink with extreme force.
USE_LANGUAGES=			# avoid wrapper scripts
PREPEND_PATH+=			${PREFIX}/bin
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/x86_64-w64-mingw32
CPPFLAGS+=			-I${PREFIX}/x86_64-w64-mingw32/include

post-extract:
	mkdir ${WRKDIR}/build

# XXX HACK
do-configure:
	${RUN} cd ${WRKDIR}/build && ${SETENV} ${CONFIGURE_ENV} \
	  CC=x86_64-w64-mingw32-gcc		\
	  CXX=x86_64-w64-mingw32-g++		\
	  CPP="x86_64-w64-mingw32-gcc -E"	\
	  CXXCPP="x86_64-w64-mingw32-g++ -E"	\
	  ${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}	\
	  ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include "../../mk/bsd.pkg.mk"
