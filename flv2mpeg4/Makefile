# $NetBSD: Makefile,v 1.3 2012/09/28 22:39:13 asau Exp $

DISTNAME=	flv2mpeg4-${FLV2MPEG_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	# not defined

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://vixy.net/
COMMENT=	Flash video to MPEG4 transcoder

INSTALL_DIRS=	bin
DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

SVN_REPOSITORIES+=	flv2mpeg4
SVN_ROOT.flv2mpeg4=	${SVN_ROOT_SOURCEFORGE}/vixynet/trunk/flv2mpeg4
SVN_MODULE.flv2mpeg4=	${DISTNAME}
SVN_CERTS=		files/dc5a395eac239ee84380e60694cec8f1

SOURCES=	avformat_writer.c dcprediction.c flv2mpeg4.c fetch.c
SOURCES+=	flvdecoder.c m4vencode.c mp3header.c
LIBS=		-lavformat -lavcodec
do-build:
	cd ${WRKSRC}/src;						\
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} ${SOURCES}	\
		-o ${WRKSRC}/flv2mpeg4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flv2mpeg4 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "version.mk"

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
