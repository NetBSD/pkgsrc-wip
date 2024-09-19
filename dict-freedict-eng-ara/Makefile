# $NetBSD: Makefile,v 1.5 2014/01/29 17:29:20 cheusov Exp $
#

DISTNAME=	freedict-eng-ara-0.0.2
PKGNAME=	dict-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freedict/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.freedict.org/ar/
COMMENT=	Dict package for English-Arabic Freedict dictionary
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		dict-server>=1.10.2:../../textproc/dict-server
DEPENDS+=		dict-server>=1.9.14:../../textproc/dict-server

DICTSRCNAME=	${DISTNAME:S/freedict-//S/-0.0.2//}

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gzip

DICTNAME=		freedict_${DICTSRCNAME}
DICTD_DB_DIR=		${PREFIX}/share/dictd
FILES=			${DICTNAME}.index ${DICTNAME}.dict.dz

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
