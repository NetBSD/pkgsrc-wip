# $NetBSD: Makefile,v 1.6 2005/02/06 19:20:58 poppnk Exp $

DISTNAME=	libparsifal-0.9.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/
COMMENT= 	XML parser with implementation SAX2

USE_BUILDLINK3= YES
GNU_CONFIGURE=  YES

#CONFIGURE_ARGS+=--prefix=${LOCALBASE}

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
