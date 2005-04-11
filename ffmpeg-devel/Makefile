# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:00 tvierling Exp $

DISTNAME=	ffmpeg-0.4.9-pre1
PKGNAME=	ffmpeg-devel-0.4.9pre1
CATEGORIES=	wip multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	zul@NetBSD-fr.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

HAS_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES

CONFLICTS+=	ffmpeg-[0-9]*

REPLACE_PERL=	doc/texi2pod.pl

CONF_FILES=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=		--cc=${CC} --prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-pp --disable-vhook --disable-debug
CONFIGURE_ARGS+=	--enable-gpl
CONFIGURE_ARGS+=	--enable-ffplay

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ffmpeg \
		${PREFIX}/share/doc/ffmpeg \
		${PREFIX}/include/ffmpeg/libpostproc
	${INSTALL_DATA} ${WRKSRC}/libavcodec/apiexample.c \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/TODO \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.txt \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/share/examples/ffmpeg
	# ffplay not installed
	if [ -f ${PREFIX}/man/man1/ffplay.1 ]; then \
	${RM} ${PREFIX}/man/man1/ffplay.1 ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/libavcodec/libpostproc/postprocess.h \
		${PREFIX}/include/ffmpeg/libpostproc

.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
