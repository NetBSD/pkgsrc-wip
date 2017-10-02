# $NetBSD$

DISTNAME=	qrupdate-1.1.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qrupdate/}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://qrupdate.sourceforge.io/
COMMENT=	Library for fast updating of QR and Cholesky decompositions
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=    yes
USE_LANGUAGES=	fortran
USE_TOOLS=      gmake

MAKE_FLAGS= FC=${FC:Q} FFLAGS=${FFLAGS:Q} PREFIX=${PREFIX:Q} LIBDIR=lib

do-build:
	cd ${WRKDIR}/${DISTNAME}/src && gmake ${MAKE_FLAGS} lalib

do-install:
	cd ${WRKDIR}/${DISTNAME}/src && gmake DESTDIR=${DESTDIR}/ ${MAKE_FLAGS} lainstall

.include "../../mk/bsd.pkg.mk"
