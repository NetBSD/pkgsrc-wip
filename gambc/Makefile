# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=	gambc-${GAMBC_DIST_VERSION}
PKGNAME=	gambc-${GAMBC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v4.4/source/
EXTRACT_SUFX=	.tgz

MAINTAINER= oivulf@gmail.com
HOMEPAGE=	http://dynamo.iro.umontreal.ca/~gambit/wiki/index.php/Main_Page
COMMENT=	GambitC Scheme System

NOT_FOR_BULK_PLATFORM+=	SunOS-*-*

# bin/scheme-r5rs
CONFLICTS+=	scheme48>=1.2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-single-host
#CONFIGURE_ARGS+=	--enable-cplusplus  #breaks c code ld
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=  --docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--disable-gcc-opts

INFO_FILES=		yes
MAKE_FILE=		makefile

BUILD_TARGET+=		bootstrap all doc 
TEST_TARGET=		check
LDFLAGS += -L${WRKSRC}/lib -L${WRKSRC}/gsi -L${WRKSRC}/gsc
CHECK_PORTABILITY_SKIP=	prebuilt/*/*
DLOPEN_REQUIRE_PTHREADS=no

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"


MAKE_FLAGS+=		${GAMBC_MAKE_FLAGS}

SUBST_CLASSES+=		build
SUBST_FILES.build=	configure
SUBST_FILES.build+=	makefile.in */makefile.in */*/makefile.in
SUBST_MESSAGE.build=	Preparing build-time and installation configuration.
SUBST_SED.build=	-e 's|v${GAMBC_DIST_VERSION}||'
SUBST_SED.build+=	-e 's|@target_vendor@|The NetBSD Foundation, Inc.|g'
SUBST_STAGE.build=	pre-configure
SUBST_VARS.build+=	PACKAGE_SUBDIR PACKAGE_VERSION
SUBST_VARS.build+=	PACKAGE_STRING

PACKAGE_SUBDIR=		# empty
PACKAGE_VERSION=	${PKGVERSION}
PACKAGE_STRING=		${${PKGBASE} ${PKGVERSION}:L}

.include "version.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
