# $NetBSD: Makefile,v 1.8 2012/10/03 14:34:49 asau Exp $
#

DISTNAME=		mpgedit_0-7p2beta_src
PKGNAME=		mpgedit-0.7.1.99
EXTRACT_SUFX=		.tgz
WRKSRC=			${WRKDIR}/${DISTNAME}/mpgedit
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.mpgedit.org/mpgedit/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mpgedit.org/mpgedit/
COMMENT=		MPEG audio file editor

MAKE_FILE=		makefile.linux

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xmpgedit
	cd ${WRKSRC} && for f in mpgedit.1 xmpgedit.1 decoder.so.1 mp3decoder.sh.1 \
		scramble_times.pl.1 scramble.pl.1 unscramble.pl.1; do \
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done; \
	for f in libdecoder_mpg123.so libdecoder_popen.so libmpglib_mpgedit.so; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/lib; \
	done; \
	for f in mpgedit mpgedit_nocurses gui/xmpgedit; do \
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/bin; \
	done; \
	${INSTALL_SCRIPT} mp3decoder.sh ${DESTDIR}${PREFIX}/bin; \
	for f in eject.xpm pause.xpm record.xpm next_t.xpm play.xpm stop.xpm; do \
		${INSTALL_DATA} gui/$$f ${DESTDIR}${PREFIX}/share/xmpgedit; \
	done
	${RM} -f ${DESTDIR}${PREFIX}/lib/libmpgedit_decoder.so
	${LN} -s libdecoder_mpg123.so ${DESTDIR}${PREFIX}/lib/libmpgedit_decoder.so

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
