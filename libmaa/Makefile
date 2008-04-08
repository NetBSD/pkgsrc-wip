# $NetBSD: Makefile,v 1.12 2008/04/08 20:14:16 cheusov Exp $

DISTNAME=	dictd-1.10.11
PKGNAME=	libmaa-1.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.dict.org/
COMMENT=	Provides a few data structures and helpful functions

PKG_DESTDIR_SUPPORT=	user-destdir

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
		${INSTALL_DATA} ${WRKSRC}/"$${i}" ${DESTDIR}${PKGDOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
