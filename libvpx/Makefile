# $NetBSD: Makefile,v 1.4 2010/10/12 18:18:34 rxg Exp $
#

DISTNAME=	libvpx-0.9.2
DISTFILES=	${DISTNAME:S,-,-v,}${EXTRACT_SUFX}
CATEGORIES=	multimedia
MASTER_SITES=	http://webm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/webm/
COMMENT=	On2 VP8 library from Google
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake bash:build perl:build

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

HAS_CONFIGURE=	YES
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing bash paths.
SUBST_FILES.fix-paths=		configure \
				build/make/version.sh \
				build/make/gen_asm_deps.sh \
				examples/gen_example_text.sh \
				examples/gen_example_code.sh
SUBST_SED.fix-paths=		-e 's,/bin/bash,${BASH},g'

CONFIGURE_ARGS+=	--enable-pic \
			--disable-postproc \
			--enable-runtime-cpu-detect \
			--prefix=${PREFIX}

BUILD_TARGET=	# none

post-extract:
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
