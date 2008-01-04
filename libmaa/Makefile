# $NetBSD: Makefile,v 1.9 2008/01/04 10:28:25 cheusov Exp $

DISTNAME=	dictd-1.10.10
PKGNAME=	libmaa-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.dict.org/
COMMENT=	Provides a few data structures and helpful functions

WRKSRC=			${WRKDIR}/${DISTNAME}/libmaa
BUILD_TARGET=		lib

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR} lib include

EXTRA_DOC_FILES=	COPYING.LIB README doc/libmaa.600dpi.ps

post-install:
	set -e; \
	for i in ${EXTRA_DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$${i}" ${PKGDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
