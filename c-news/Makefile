# $NetBSD: Makefile,v 1.6 2005/04/11 21:10:25 tvierling Exp $

DISTNAME=	c-news
PKGNAME=        c-news-CR-7
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pgpverify-1.12

PATCH_SITES=	ftp://ftp.lan-ks.de/pub/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
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

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://www.dinoex.net/c-news.html
COMMENT=	The 3rd generation USENET news server

CONFLICTS+=	nntpclnt-[0-9]* inn*

WRKSRC=		${WRKDIR}
USE_PKGINSTALL=	YES
PKG_USERS=	news:news::Internet\\ News:${CNEWSDATA}:${SH}
PKG_GROUPS=	news

PKG_SYSCONFDIR.c-news=     ${CNEWSDATA}/etc

EGDIR=		${PREFIX}/share/examples/c-news


.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
# groff & pic
BUILD_DEPENDS+=	groff:../../textproc/groff
PIC?=		gpic
NROFF?=		groff -Tascii -mtty-char
.else
PIC?=		pic
NROFF?=		nroff -Tascii
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
CONFLICTS=	inn-[1-9]*
MAKEFILE=	makefile
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

.if (${OPSYS} == "SunOS")
FILES_SUBST_SED+=	"-e s!statfs!statvfs!g"
.endif

pre-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PGPVERIFY} ${WRKSRC}/${PGPVERIFY}

pre-configure:
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/substitutions > ${WRKDIR}/conf/substitutions
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/quiz.def > ${WRKDIR}/conf/quiz.def
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/config.make > ${WRKDIR}/include/config.make
	${CP}  ${FILESDIR}/makeinc ${WRKDIR}/conf/makeinc
	${CP}  ${FILESDIR}/makefile.notebook ${WRKDIR}/notebook/makefile

# One of the tests does not work correctly if we are in a union-mounted
# directory.
post-build:     build-doc # regression

regression:
	cd ${WRKSRC} && ${MAKE} ${MAKEFLAGS} r

build-doc:
	cd ${WRKSRC}/doc && \
		${MAKE} PIC=${PIC} NROFF=${NROFF} ${MAKE_FLAGS}
	cd ${WRKSRC}/notebook && ${MAKE} ${MAKE_FLAGS}

do-install:
	${RM} -f ${PREFIX}/bin/inews
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${PREFIX}/lib
	${MKDIR} ${CNEWSARTS} ${CNEWSOV} ${CNEWSBIN} ${CNEWSCTL}
	${CHOWN} ${BINOWN}:${BINGRP} ${CNEWSBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/${PGPVERIFY} ${CNEWSBIN}/pgpverify
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} setup
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck
.for f in checknews cnewsdo inews injnews postnews readnews
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/$f
.endfor
	${CHOWN} -R news:news ${CNEWSARTS} ${CNEWSOV} ${CNEWSCTL}
	${CHOWN} news:news ${CNEWSBIN}/input/newsspool
	${CHMOD} 6555 ${CNEWSBIN}/input/newsspool
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man1/${i:R}.1
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man5/${i:R}.5
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man8/${i:R}.8
.endfor
	# install docs:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/cnews
.for i in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/cnews
.endfor
.for i in ${NOTEBOOK}
	${INSTALL_MAN} ${WRKSRC}/notebook/${i} ${PREFIX}/share/doc/cnews
.endfor
	# install sample config files
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cnews
	for FILE in `ls -1 ${WRKSRC}/conf/*.eg` \
		${WRKSRC}/conf/cron.proto ${WRKSRC}/conf/organization; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/cnews; \
	done

.include "../../mk/bsd.pkg.mk"
