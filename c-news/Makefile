# $NetBSD: Makefile,v 1.27 2015/02/01 21:01:33 hfath Exp $

DISTNAME=	c-news
PKGNAME=	c-news-CR-7
PKGREVISION=	3
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DEFAULT_DISTFILES} pgpverify-1.12

PATCH_SITES=	ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	c-news-patch-fileart.c c-news-patch-namecheck.awk \
		c-news-patch-newsrun c-news-patch-sendbatches \
		c-news-patch-ctl-pgp3 c-news-patch-ctl-more \
		c-news-patch-ctl-regexp \
		c-news-patch-doexpire c-news-patch-queuelen.tay \
		c-news-patch-bunzip2 \
		c-news-patch-ctl-underscore \
		c-news-patch-y2k-2 \
		c-news-patch-inews-path \
		c-news-patch-expovguts.c \
		c-news-patch-pgpverify-1.12-perl4 \
		c-news-patch-gawk3

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.dinoex.net/c-news.html
COMMENT=	The 3rd generation USENET news server
LICENSE=	c-news-license
LICENSE_FILE=	c-news-license

# Not yet 64 bit time_t safe
NOT_FOR_PLATFORM=	NetBSD-5.99.*-* NetBSD-[6-9]*-*

MAKE_JOBS_SAFE=		no

CONFLICTS+=	nntpclnt-[0-9]* inn-[0-9]*

WRKSRC=		${WRKDIR}
PKG_USERS=	news:news::Internet\ News:${CNEWSDATA:Q}:${SH:Q}
PKG_GROUPS=	news

PKG_SYSCONFDIR.c-news=	${CNEWSDATA}/etc

EGDIR=		${PREFIX}/share/examples/c-news

# Debugging aids
CFLAGS+=		-Wall -Wno-error
DBG=			-O -g3
INSTALL_UNSTRIPPED =	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0123].*))
DEPENDS+=	uucp-[1-9]*:../../net/uucp
.endif

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=	regression
.endif

USE_TOOLS+=	perl:run
REPLACE_PERL+=	${PGPVERIFY:Q}

.if (${OPSYS} == "SunOS")
# groff & pic
USE_TOOLS+=	groff
PIC?=		gpic
NROFF?=		groff -Tascii -mtty-char
.else
USE_TOOLS+=	nroff
PIC?=		pic
NROFF?=		nroff -Tascii
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAKE_FILE=	makefile
DIST_SUBDIR=	${DISTNAME}

.include "Makefile.common"

MAN1=		checknews.1cn inews.1cn postnews.1cn readnews.1cn
MAN5=		controlperm.5 news.5 newsctl.5 newsdb.5 newsoverview.5 \
		newssys.5
MAN8=		cnewsdo.8cn expire.8cn explode.8cn mergeactive.8 \
		mkhistory.8cn newsaux.8cn newsbatch.8cn newsmail.8cn \
		newsmaint.8cn newsoverview.8 relaynews.8cn report.8cn \
		rnews.8cn

DOCS=		guide.more guide.ps index.ps toc.ps
NOTEBOOK=	locking.more makefiles.more locking.ps makefiles.ps

PGPVERIFY?=	pgpverify-1.12

pre-patch:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PGPVERIFY:Q} ${WRKSRC}/${PGPVERIFY:Q}

pre-configure:
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/substitutions > ${WRKDIR}/conf/substitutions
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/quiz.def > ${WRKDIR}/conf/quiz.def
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.make > ${WRKDIR}/include/config.make
	${CP}  ${FILESDIR}/makeinc ${WRKDIR}/conf/makeinc
	${CP}  ${FILESDIR}/makefile.notebook ${WRKDIR}/notebook/makefile

# One of the regression tests does not work correctly if we are in
# a union-mounted directory. In that case, build outside the union-mounted
# tree with something like "env WRKOBJDIR=/var/tmp make".
post-build:     build-doc

.PHONY: regression
regression:
	cd ${WRKSRC} && ${MAKE} ${MAKEFLAGS} r

.PHONY: build-doc
build-doc:
	cd ${WRKSRC}/doc && \
		${MAKE} PIC=${PIC:Q} NROFF=${NROFF:Q} ${MAKE_FLAGS}
	cd ${WRKSRC}/notebook && ${MAKE} ${MAKE_FLAGS}

do-install:
	${RM} -f ${PREFIX}/bin/inews
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${PREFIX}/lib
	${MKDIR} ${CNEWSARTS} ${CNEWSOV} ${CNEWSBIN} ${CNEWSCTL}
	${CHOWN} ${BINOWN}:${BINGRP} ${CNEWSBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/${PGPVERIFY:Q} ${CNEWSBIN:Q}/pgpverify
	cd ${WRKSRC} && ${MAKE} ${MAKE_FLAGS} ${MAKE_FILE} install
	cd ${WRKSRC} && ${MAKE} ${MAKE_FLAGS} ${MAKE_FILE} setup
	cd ${WRKSRC} && ${MAKE} ${MAKE_FLAGS} ${MAKE_FILE} ui readpostcheck
.for f in checknews cnewsdo inews injnews postnews readnews
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/${f:Q}
.endfor
	${CHOWN} -R news:news ${CNEWSARTS} ${CNEWSOV} ${CNEWSCTL}
	${CHOWN} news:news ${CNEWSBIN:Q}/input/newsspool
	${CHMOD} 6555 ${CNEWSBIN:Q}/input/newsspool
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${i:Q} ${PREFIX}/${PKGMANDIR}/man1/${i:R:Q}.1
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${i:Q} ${PREFIX}/${PKGMANDIR}/man5/${i:R:Q}.5
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${i:Q} ${PREFIX}/${PKGMANDIR}/man8/${i:R:Q}.8
.endfor
	# install docs:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cnews
.for i in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i:Q} ${PREFIX}/share/doc/cnews
.endfor
.for i in ${NOTEBOOK}
	${INSTALL_MAN} ${WRKSRC}/notebook/${i:Q} ${PREFIX}/share/doc/cnews
.endfor
	# install sample config files
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cnews
	set -e; \
	for FILE in `ls -1 ${WRKSRC}/conf/*.eg` \
		${WRKSRC}/conf/cron.proto ${WRKSRC}/conf/organization; do \
	  ${INSTALL_DATA} "$$FILE" ${PREFIX}/share/examples/cnews; \
	done

.include "../../mk/bsd.pkg.mk"
