# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:36 asau Exp $
#

DISTNAME=	freedict-eng-ara-0.0.2
PKGNAME=	dict-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://garr.dl.sourceforge.net/project/freedict/English%20-%20Arabic/0.0.2/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.freedict.org/ar/
COMMENT=	Dict package for English-Arabic Freedict dictionary
LICENSE=	gnu-gpl-v2

DEPENDS+=		dict-server>=1.9.14:../../textproc/dict-server
BUILD_DEPENDS+=		dict-server>=1.10.2:../../textproc/dict-server

DICTSRCNAME=	${DISTNAME:S/freedict-//S/-0.0.2//}

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gzip

DICTNAME=		freedict_${DICTSRCNAME}
DICTD_DB_DIR=		${PREFIX}/share/dictd
FILES=			 ${DICTNAME}.index ${DICTNAME}.dict.dz

INSTALLATION_DIRS=	${DICTD_DB_DIR}

do-build:
	cd ${WRKSRC} && \
	gzip -dc ${DICTSRCNAME}.dict.dz > ${DICTSRCNAME}.dict && \
	${PREFIX}/bin/dictunformat ${DICTSRCNAME}.index \
		< ${DICTSRCNAME}.dict > dict.c5 && \
	${PREFIX}/bin/dictfmt -t --utf8 ${DICTNAME} < dict.c5 && \
	${PREFIX}/bin/dictzip ${DICTNAME}.dict

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${DESTDIR}${DICTD_DB_DIR}



.include "../../mk/bsd.pkg.mk"
