# $NetBSD: Makefile,v 1.4 2004/05/07 12:20:20 cjep Exp $

DISTNAME=	libparsifal-0.7.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/
COMMENT= 	XML parser with implementation SAX2

USE_BUILDLINK2= YES
HAS_CONFIGURE=  YES

CONFIGURE_ARGS+=--prefix=${LOCALBASE}

WRKSRC=${WRKDIR}/libparsifal-0.7.3

SRC_FILES=`ls ${WRKSRC}/src/*.c`
INC_FILES=`ls ${WRKSRC}/include/libparsifal/*.h`

pre-build:

	@for f in ${SRC_FILES}; do \
		${TR} -d "\r" < $${f} > $${f}; \
	done

	@for f in ${INC_FILES}; do \
		${TR} -d "\r" < $${f} > $${f}; \
	done

.include "../../mk/bsd.pkg.mk"
