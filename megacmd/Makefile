# $NetBSD: Makefile,v 1.9 2025/01/27 12:09:02 wiz Exp $

DISTNAME=	megacmd-2.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=meganz/}
GITHUB_PROJECT=	MEGAcmd
GITHUB_TAG=	${PKGVERSION_NOREV}_Linux
SDK_VERSION=	v8.3.1

GITHUB_SUBMODULES=	meganz sdk ${SDK_VERSION} sdk

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://mega.io/
COMMENT=	CLI and scriptable application to access MEGA
# MEGAcmd: GPLv3, SDK: BSD 2-clause
LICENSE=	gnu-gpl-v3 AND 2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	filesystem
FORCE_CXX_STD=		c++17
USE_LIBTOOL=		yes
#USE_TOOLS+=		autoreconf autoconf automake gmake
USE_TOOLS+=		pkg-config
#GNU_CONFIGURE=		yes
REPLACE_SH=		src/client/mega-*
CXXFLAGS+=		-DCRYPTOPP_DISABLE_ASM

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DFULL_REQS=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_MEDIAINFO=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FREEIMAGE=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_PDFIUM=OFF


#CONFIGURE_ARGS+=	--disable-examples
#CONFIGURE_ARGS+=	--disable-java
#CONFIGURE_ARGS+=	--disable-php
#CONFIGURE_ARGS+=	--disable-python
#CONFIGURE_ARGS+=	--without-termcap
#CONFIGURE_ARGS+=	--without-libraw
#CONFIGURE_ARGS+=	--without-libzen
#CONFIGURE_ARGS+=	--without-rt
#CONFIGURE_ARGS+=	--enable-gcc-hardening

CHECK_PORTABILITY_SKIP+=	sdk/bindings/ios/3rdparty/*.sh

INSTALLATION_DIRS+=	share/doc/megacmd

#pre-configure:
#	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd_completion.sh \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd
	${INSTALL_DATA} ${FILESDIR}/README ${DESTDIR}${PREFIX}/share/doc/megacmd

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../multimedia/libmediainfo/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
