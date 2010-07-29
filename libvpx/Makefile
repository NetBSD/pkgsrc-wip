# $NetBSD: Makefile,v 1.1.1.1 2010/07/29 00:39:27 ryo-on Exp $
#

DISTNAME=	libvpx-0.9.1
CATEGORIES=	multimedia
MASTER_SITES=	http://webm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://webm.googlecode.com/files/
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
				examples/gen_example_code.sh
SUBST_SED.fix-paths=		-e 's,/bin/bash,${PREFIX}/bin/bash,g'

CONFIGURE_ARGS=		--enable-pic \
			--enable-postproc \
			--enable-runtime-cpu-detect \
			--prefix=${PREFIX} \
			--enable-shared

BUILD_TARGET=	# none

.include "../../mk/bsd.pkg.mk"
