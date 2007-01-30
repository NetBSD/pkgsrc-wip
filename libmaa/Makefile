# $NetBSD: Makefile,v 1.5 2007/01/30 19:15:52 cheusov Exp $

DISTNAME=	dictd-1.10.7
PKGNAME=	libmaa-0.990
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.dict.org/
COMMENT=	Library that provides many low-level data structures

WRKSRC=		${WRKDIR}/${DISTNAME}/libmaa

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=		lib
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--enable-shared

PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR}

EXTRA_DOC_FILES=	COPYING.LIB README doc/libmaa.600dpi.ps

post-install:
	set -e; \
	for i in $${EXTRA_DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$${i}" ${PKGDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
