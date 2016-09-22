# $NetBSD: Makefile,v 1.2 2013/05/10 16:51:09 shattered Exp $

DISTNAME=	ffmpeg-${PKGREVISION}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://source.ffmpeg.org/ffmpeg.git
GIT_MODULE.master=	ffmpeg
# _GIT_FLAGS?=		--depth 1
WRKSRC=			${WRKDIR}/ffmpeg

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc

INSTALLATION_DIRS=	lib share/examples/ffmpeg share/doc/ffmpeg

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
 || !empty(MACHINE_PLATFORM:MSunOS-*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../wip/mk/git-package.mk"

.include "Makefile.common"
