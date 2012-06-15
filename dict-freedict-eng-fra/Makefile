# $NetBSD: Makefile,v 1.10 2012/06/15 00:03:02 othyro Exp $
#

DISTNAME=	eng-fra
PKGNAME=	dict-freedict-${DISTNAME}-0.0.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freedict/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.freedict.org/
COMMENT=	DICTD data for FreeDict English-French dictionary
LICENSE=	gnu-gpl-v2

DICTSRCNAME=	${DISTNAME}

USE_TOOLS+=		gzip

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		dict-server>=1.9.14:../../textproc/dict-server
BUILD_DEPENDS+=		dict-server>=1.10.2:../../textproc/dict-server

DICTD_DB_DIR=		${PREFIX}/share/dictd
INSTALLATION_DIRS+=	${DICTD_DB_DIR}

WRKSRC=			${WRKDIR}/bin

DICTNAME=		freedict_${DICTSRCNAME}
FILES=			${DICTNAME}.index ${DICTNAME}.dict.dz

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
