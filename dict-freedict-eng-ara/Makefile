# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 09:57:26 jihbed Exp $
#

DISTNAME=	freedict-eng-ara-0.0.2
PKGNAME=	dict-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://garr.dl.sourceforge.net/project/freedict/English%20-%20Arabic/0.0.2/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.freedict.org/ar/
COMMENT=	Dict package for English-Arabic Freedict dictionary

DEPENDS+=		dict-server>=1.9.14:../../textproc/dict-server
BUILD_DEPENDS+=		dict-server>=1.10.2:../../textproc/dict-server

PKG_DESTDIR_SUPPORT=	user-destdir

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
