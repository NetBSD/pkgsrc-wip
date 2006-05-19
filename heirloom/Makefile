# $NetBSD: Makefile,v 1.6 2006/05/19 14:51:23 cheusov Exp $

DISTNAME=	heirloom-060122
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://heirloom.sf.net/
COMMENT=	Collection of standard Unix utilities

USE_TOOLS+=	yacc lex

# should be partially ported to Interix
NOT_FOR_PLATFORM=	Interix-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "FreeBSD" #|| ${OPSYS} == "DragonFly"
LDFLAGS+=	-lkvm
.endif

LCRYPT=		-lcrypt
.if ${OPSYS} == "OpenBSD"
LCRYPT=
.endif

LCURS=-lcurses
USE_BZLIB=	1

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DUSE_TERMCAP
LCURS=		-ltermcap
.endif

.if ${OPSYS} == "Linux"
CPPFLAGS+=	-D_GNU_SOURCE
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64L
.endif

LDFLAGS+=	-lz -lbz2

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} LCRYPT=${LCRYPT:Q} LCURS=${LCURS:Q} DESTDIR=${PREFIX:Q} -f makefile

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} LCRYPT=${LCRYPT:Q} LCURS=${LCURS:Q} DESTDIR=${PREFIX:Q} install

DOC_FILES=	COPYING COPYING.LGPL \
		LICENSE LUCENT \
		OPENSOLARIS.LICENSE README

DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR} && \
	${INSTALL_DATA_DIR} ${DOC_DIR}/LICENSE && \
	${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR} && \
	for i in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/LICENSE/$${i} \
		                ${DOC_DIR}/LICENSE || exit 1; \
	done

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
