# $NetBSD: Makefile,v 1.1 2006/05/13 15:12:26 cheusov Exp $

DISTNAME=	Mueller7GPL
PKGNAME=	dict-mueller7-1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.geocities.com/mueller_dic/ \
		http://mueller-dic.chat.ru/ \
		http://www.chat.ru/~mueller_dic/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mueller-dic.chat.ru/
COMMENT=	DICTD data for English-Russian dictionary by Mueller

DEPENDS+=	dict-server-[0-9]*:../../textproc/dict-server

BUILD_DEPENDS+=	dict-server>=1.9.14:../../textproc/dict-server
BUILD_DEPENDS+=	p5-Unicode-Map8-[0-9]*:../../converters/p5-Unicode-Map8

# we need GNU fmt
BUILD_DEPENDS+= coreutils-[0-9]*:../../sysutils/coreutils

WRKSRC=		${WRKDIR}/usr/local/share/dict

USE_TOOLS+=	gsed perl #gfmt is unfortunately not supported

pre-configure:
	${CP} files/mueller2utf8 files/to-dict ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	${SH} to-dict --src-data Mueller7GPL.koi mueller7.data > /dev/null && \
	${PERL5} mueller2utf8 < mueller7.data > tmp_1 && \
	dictfmt --utf8 -p --columns 0 \
		-s 'Mueller English-Russian Dictionary' \
		-u 'http://www.chat.ru/~mueller_dic' \
		--headword-separator ', ' mueller7 < tmp_1 && \
	dictzip *.dict

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd && \
	${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${WRKSRC}/*.index \
		${PREFIX}/share/dictd

.include "../../mk/bsd.pkg.mk"
