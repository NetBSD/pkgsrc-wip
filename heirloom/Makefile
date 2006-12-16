# $NetBSD: Makefile,v 1.13 2006/12/16 23:36:20 cheusov Exp $

.include "Makefile.common"

CATEGORIES=	sysutils

MAINTAINER=	cheusov@tut.by
COMMENT=	Collection of standard Unix utilities

USE_TOOLS+=	yacc lex

# should be partially ported to Interix
NOT_FOR_PLATFORM=	Interix-*-*

MAKE_FILE=		makefile
HLROOT=			heirloom
PLIST_SUBST+=		HLROOT=${HLROOT}

.include "../../mk/bsd.prefs.mk"

CFLAGS.Linux+=		-D_GNU_SOURCE -D_FILE_OFFSET_BITS=64L

LDFLAGS.NetBSD+=	-lkvm
LDFLAGS.FreeBSD+=	-lkvm
LDFLAGS.OpenBSD+=	-lkvm
LDFLAGS.DragonFly+=	-lkvm

LCRYPT=		-lcrypt
.if ${OPSYS} == "OpenBSD"
LCRYPT=
.endif

LCURS=-lcurses

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DUSE_TERMCAP
LCURS=		-ltermcap
.endif

LDFLAGS+=	-lz -lbz2

MAKE_FLAGS+=    LCURS=${LCURS}
MAKE_FLAGS+=    LCRYPT=${LCRYPT}
MAKE_FLAGS+=    PREFIX=${PREFIX:Q}/${HLROOT}
MAKE_FLAGS+=    UCBINST=${INSTALL}
MAKE_FLAGS+=	IUXRE="-I../libuxre -DUXRE"
MAKE_FLAGS+=	LUXRE="-L../libuxre -luxre"

DOC_FILES=	COPYING COPYING.LGPL \
		LICENSE LUCENT \
		OPENSOLARIS.LICENSE README
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=${DOC_DIR} ${DOC_DIR}/LICENSE ${PREFIX}
.for i in bin/posix bin/posix2001 bin/s42 bin etc/default etc lib/spell \
          lib/tmac lib man/man1 man/man1b man/man1m man/man2 man/man3 \
          man/man4 man/man5 man/man6 man/man7 man/man8 man sbin ucb \
          var/adm var/log var
INSTALLATION_DIRS+=	${PREFIX}/heirloom/${i}
.endfor

pre-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f makefile makefiles

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR} && \
	for i in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/LICENSE/"$${i}" \
		                ${DOC_DIR}/LICENSE || exit 1; \
	done

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
