# $NetBSD: Makefile,v 1.4 2007/01/06 20:24:20 shattered Exp $

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

DEPENDS+=	dict-server>=1.9.14*:../../wip/dict-server

BUILD_DEPENDS+=	dict-server>=1.10.2:../../wip/dict-server
BUILD_DEPENDS+=	p5-Unicode-Map8-[0-9]*:../../converters/p5-Unicode-Map8
BUILD_DEPENDS+=	metamail-[0-9]*:../../mail/metamail

# we need GNU fmt
BUILD_DEPENDS+= coreutils-[0-9]*:../../sysutils/coreutils

WRKSRC=		${WRKDIR}/mueller7/usr/local/share/dict

USE_TOOLS+=	gsed perl tar #gfmt is unfortunately not supported

pre-configure:
	cp files/mueller2utf8 files/to-dict ${WRKSRC}

do-extract:
	mkdir ${WRKDIR}/mueller7
	cd ${WRKDIR}/mueller7 && \
	bzip2 -dc ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | tar -xf -

do-build:
	cd ${WRKSRC} && \
	sh to-dict --src-data Mueller7GPL.koi mueller7.data > /dev/null && \
	perl mueller2utf8 < mueller7.data > tmp_1 && \
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
