# $NetBSD: Makefile,v 1.3 2007/01/07 13:48:10 cheusov Exp $

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
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
