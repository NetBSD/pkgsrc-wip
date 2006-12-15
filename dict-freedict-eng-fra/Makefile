# $NetBSD: Makefile,v 1.2 2006/12/15 22:20:09 cheusov Exp $

DISTNAME=	eng-fra
PKGNAME=	dict-freedict-${DISTNAME}-0.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freedict/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://freedict.de/
COMMENT=	DICTD data for FreeDict English-French dictionary

DICTSRCNAME=	${DISTNAME}

USE_TOOLS+=	gzip

DEPENDS+=	dict-server>=1.9.14:../../wip/dict-server
BUILD_DEPENDS+=	dict-server>=1.10.2:../../wip/dict-server

DICTD_DB_DIR=		${PREFIX}/share/dictd
INSTALLATION_DIRS=	${DICTD_DB_DIR}

WRKSRC=		${WRKDIR}/bin

FILES=		freedict_eng-fra.index freedict_eng-fra.dict.dz
DICTNAME=	freedict_${DICTSRCNAME}

do-build:
	cd ${WRKSRC} && \
	gzip -dc ${DICTSRCNAME}.dict.dz > ${DICTSRCNAME}.dict && \
	dictunformat ${DICTSRCNAME}.index \
		< ${DICTSRCNAME}.dict > dict.c5 && \
	dictfmt -t --utf8 ${DICTNAME} < dict.c5 && \
	dictzip ${DICTNAME}.dict

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${DICTD_DB_DIR}

.include "../../mk/bsd.pkg.mk"
