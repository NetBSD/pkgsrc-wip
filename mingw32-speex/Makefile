# $NetBSD: Makefile,v 1.2 2003/12/08 18:38:05 mpasternak Exp $
#

DISTNAME=	speex-1.0.2
PKGNAME=	${MINGW_PKG_PREFIX}${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec

CFILES=	bits.c cb_search.c exc_10_16_table.c exc_10_32_table.c \
	exc_20_32_table.c exc_5_256_table.c exc_5_64_table.c exc_8_128_table.c \
	filters.c gain_table.c gain_table_lbr.c hexc_10_32_table.c hexc_table.c \
	high_lsp_tables.c lpc.c lsp.c lsp_tables_nb.c ltp.c math_approx.c misc.c \
	modes.c nb_celp.c quant_lsp.c sb_celp.c speex_callbacks.c speex_header.c \
	stereo.c vbr.c vq.c

INCFILES=speex.h speex_bits.h speex_callbacks.h speex_header.h speex_stereo.h

do-build:
	cd ${WRKSRC}/libspeex && for a in ${CFILES}; do \
		${CC} -c $$a; \
	done       
	cd ${WRKSRC}/libspeex && ${CC} -shared -o libspeex-1.0.dll -Wl,--out-implib=libspeex.a *.o
	
do-install:
	${INSTALL_DATA} ${WRKSRC}/libspeex/libspeex-1.0.dll ${PREFIX}/${MINGWTARGET}/lib
	${INSTALL_DATA} ${WRKSRC}/libspeex/libspeex.a ${PREFIX}/${MINGWTARGET}/lib
	for a in ${INCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/libspeex/$$a ${PREFIX}/${MINGWTARGET}/include/$$a; \
	done

BUILD_DEPENDS+=	${MINGW_PKG_PREFIX}libogg>=1.0:../../wip/mingw32-libogg/

.include "../../wip/mk/win32.pkg.mk"
