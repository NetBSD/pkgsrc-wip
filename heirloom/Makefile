# $NetBSD: Makefile,v 1.1 2006/04/29 16:37:43 cheusov Exp $

DISTNAME=	heirloom-060122
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://heirloom.sf.net/
COMMENT=	Collection of standard Unix utilities

# should be partially ported to Interix
NOT_FOR_PLATFORM=	Interix-*-*

# should be move in pkgsrc/mk/default/mk.conf
#HEIRLOOM_PROGRAM_PREFIX?=	hl

#TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "FreeBSD" #|| ${OPSYS} == "DragonFly"
LDFLAGS+=	-lkvm
.endif

#.if ${OPSYS} != "NetBSD"
#BUILD_DEPENDS+=	bzip2-[0-9]*:../../archivers/bzip2
#.endif

LCURS=-lcurses
USE_BZLIB=	0

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DUSE_TERMCAP
LCURS=		-ltermcap
USE_BZLIB=	1
LDFLAGS+=	-lbz2 # libbz2 is in base system
.endif

LDFLAGS+=	-lz

# Exclude programs from PLIST which aren't built on a platform.
#.if ${OPSYS} == "Interix"
#PLIST_SUBST+=		HEIRLOOM_HAVE_HOSTID="@comment "
#.else
#PLIST_SUBST+=		HEIRLOOM_HAVE_HOSTID=""
#.endif

#.if "${GNU_PROGRAM_PREFIX}" == "${HEIRLOOM_PROGRAM_PREFIX}"
#CONFLICTS+=		core-utils-[0-9]*
#.endif

PLIST_SUBST+=		HEIRLOOM_PROGRAM_PREFIX=${HEIRLOOM_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		HEIRLOOM_PROGRAM_PREFIX

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} USE_BZLIB=${USE_BZLIB:Q} LCURS=${LCURS:Q} ROOT=${PREFIX:Q} -f makefile

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} USE_BZLIB=${USE_BZLIB:Q} LCURS=${LCURS:Q} ROOT=${PREFIX:Q} install

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
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
