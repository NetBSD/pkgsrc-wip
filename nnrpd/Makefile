# $NetBSD: Makefile,v 1.18 2012/10/03 18:15:32 asau Exp $

DISTNAME=		inn-1.7.2.insync-1.1d
PKGNAME=		nnrpd-1.7.2
PKGREVISION=		3
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/OLD/1.7/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/OLD/1.7/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://www.isc.org/sw/inn/
COMMENT=		NNTP reader daemon from InterNet News (INN)

INSTALLATION_DIRS=	sbin libexec \
			share/examples/nnrpd share/doc/nnrpd \
			${PKGMANDIR}/man3 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

INN_DATA_DIR?=		/var/news

CONFLICTS+=		nntpclnt-[0-9]*
CONFLICTS+=		inn-[0-9]*

RCD_SCRIPTS=		actived
USE_TOOLS+=		perl

.include "../../mk/bsd.prefs.mk"
.include "../../wip/c-news/Makefile.common"
.include "options.mk"

# Given foo=${bar}, replace @foo@ with ${bar}.
#
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		INNDATA=${INN_DATA_DIR:Q}
FILES_SUBST+=		INNPREFIX=${PREFIX}
FILES_SUBST+=		INNMANPREFIX=${PREFIX}

# UBC brought read and mmap in sync
.if ${OPSYS} == "NetBSD" && (${OS_VERSION:M1.[0-4]*} != "" || \
		${OS_VERSION:M1.5} != "" || \
		${OS_VERSION:M1.5[A-K]} != "")
FILES_SUBST+=		INNACTSTYLE="READ"
FILES_SUBST+=		INNCFLAGS=${CFLAGS:M*:Q}
.else
FILES_SUBST+=		INNACTSTYLE="MMAP"
FILES_SUBST+=		INNCFLAGS="${CFLAGS} -DOVERSCREAM"
.endif
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/-e s!@/}

MESSAGE_SUBST+=		NEWSUID=${NEWSUID}
MESSAGE_SUBST+=		NEWSGID=${NEWSGID}

DEINSTALL_SRC=		${WRKDIR}/DEINSTALL

.for inn_dir in etc run tmp
OWN_DIRS_PERMS+=	${INN_DATA_DIR}/${inn_dir} ${NEWSUID} ${NEWSGID} 0775
.endfor
.for inn_files in nnrp.access innshellvars innshellvars.csh \
			innshellvars.pl innshellvars.tcl
CONF_FILES_PERMS+=	${PREFIX}/share/examples/nnrpd/${inn_files} \
			${INN_DATA_DIR}/etc/${inn_files} \
			${NEWSUID} ${NEWSGID} 0444
.endfor

BUILD_DEFS+=		INN_DATA_DIR

pre-configure:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/config.data > \
		${WRKSRC}/config/config.data
	${CP} ${FILESDIR}/mailpost ${WRKSRC}/samples/

post-build:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL >${WRKDIR}/DEINSTALL
	for DIR in lib actived nnrpd; do \
		${SED} -e 's#-b .OLD##' -e 's#-G#-g#' -e 's#-O#-o#'	\
			${WRKSRC}/$$DIR/Makefile			\
			> ${WRKSRC}/$$DIR/Makefile.patch;		\
		${MV} ${WRKSRC}/$$DIR/Makefile.patch			\
			${WRKSRC}/$$DIR/Makefile;			\
	done
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} Install.ms)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nnrpd/nnrpd ${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/actived/actived ${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/samples/mailpost ${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/samples/filter_nnrpd.pl \
		${DESTDIR}/${PREFIX}/libexec/
	for FILE in innshellvars innshellvars.csh innshellvars.pl \
			innshellvars.tcl; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$${FILE} 	\
			${DESTDIR}/${PREFIX}/share/examples/nnrpd/ ; \
	done
	for FILE in nnrp.access moderators; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$${FILE} 	\
			${DESTDIR}/${PREFIX}/share/examples/nnrpd/ ; \
	done
	for FILE in CONTRIBUTORS COPYRIGHT FAQ/* HISTORY 	\
		Install.ms PGPKEYS README* ; do			\
		${INSTALL_DATA} ${WRKSRC}/$${FILE} 		\
			${DESTDIR}/${PREFIX}/share/doc/nnrpd/ ; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/dbz.3 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrp.access.5 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/moderators.5 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrpd.8  \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/

.include "../../wip/c-news/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
