# $NetBSD: Makefile,v 1.11 2006/12/16 20:22:07 cheusov Exp $

.include "Makefile.common"

CATEGORIES=	sysutils

MAINTAINER=	cheusov@tut.by
COMMENT=	Collection of standard Unix utilities

USE_TOOLS+=	yacc lex

# should be partially ported to Interix
NOT_FOR_PLATFORM=	Interix-*-*

MAKE_ENV+=	IUXRE="-I../libuxre -DUXRE"
MAKE_ENV+=	LUXRE="-L../libuxre -luxre"

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

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} LCRYPT=${LCRYPT:Q} LCURS=${LCURS:Q} PREFIX=${PREFIX:Q}/heirloom -f makefile

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} LCRYPT=${LCRYPT:Q} LCURS=${LCURS:Q} PREFIX=${PREFIX:Q}/heirloom install

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
