# $NetBSD: Makefile,v 1.1.1.1 2005/01/13 14:26:22 hfath Exp $

DISTNAME=		inn-1.7.2.insync-1.1d
PKGNAME=		nnrpd-1.7.2
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/OLD/1.7/ \
			ftp://ftp.sunet.se/pub/news/nntp/inn/OLD/1.7/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/OLD/1.7/

MAINTAINER=		hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=		http://www.isc.org/inn.html
COMMENT=		NNTP reader daemon from release 1.7 of InterNet News (INN)

USE_BUILDLINK3=		YES
USE_PERL5=      	YES

USE_PKGINSTALL=		YES
INN_DATA_DIR?=		/var/news

# How do we know we have perl? Catch22...
PERL_LDOPTS!=		eval "perl -MExtUtils::Embed -e ldopts"

CONFLICTS+=		nntpclnt-[0-9]* \
			inn-[1-9].*
RCD_SCRIPTS=		actived

.include "../../mk/bsd.prefs.mk"
.include "../../wip/c-news/Makefile.common"

# Given foo=${bar}, replace @foo@ with ${bar}.
#
FILES_SUBST=		PREFIX=${PREFIX}
FILES_SUBST+=		INNDATA=${INN_DATA_DIR}
FILES_SUBST+=		INNPREFIX=${PREFIX}
FILES_SUBST+=		INNMANPREFIX=${PREFIX}
FILES_SUBST+=		PERL_LDOPTS="${PERL_LDOPTS}"
FILES_SUBST+=		PERL_INC="-I${PERL5_ARCHLIB}/CORE -DPERL_POLLUTE"

# UBC brought read and mmap in sync
.if ${OPSYS} == "NetBSD" && (${OS_VERSION:M1.[0-4]*} != "" || \
		${OS_VERSION:M1.5} != "" || \
		${OS_VERSION:M1.5[A-K]} != "")
FILES_SUBST+=		INNACTSTYLE="READ"
FILES_SUBST+=		INNCFLAGS="${CFLAGS}"
.else
FILES_SUBST+=		INNACTSTYLE="MMAP"
FILES_SUBST+=		INNCFLAGS="${CFLAGS} -DOVERSCREAM"
.endif
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/-e s!@/}

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

BUILD_DEFS+=		INN_DATA_DIR

pre-configure:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/config.data > \
		${WRKSRC}/config/config.data
	${CP} ${FILESDIR}/mailpost ${WRKSRC}/samples/

post-build:
.for FILE in DEINSTALL INSTALL
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/${FILE} >${WRKDIR}/${FILE}
.endfor
	for DIR in lib actived nnrpd; do \
		${SED} -e 's#-b .OLD##' -e 's#-G#-g#' -e 's#-O#-o#'	\
			${WRKSRC}/$$DIR/Makefile			\
			> ${WRKSRC}/$$DIR/Makefile.patch;		\
		${MV} ${WRKSRC}/$$DIR/Makefile.patch			\
			${WRKSRC}/$$DIR/Makefile;			\
	done
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} Install.ms)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nnrpd/nnrpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/actived/actived ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/samples/mailpost ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/samples/filter_nnrpd.pl ${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/samples/innshellvars.pl ${CNEWSCTL}/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nnrpd
	${INSTALL_DATA} ${WRKSRC}/samples/nnrp.access \
		${PREFIX}/share/examples/nnrpd/
	${INSTALL_DATA} ${WRKSRC}/samples/moderators \
		${PREFIX}/share/examples/nnrpd/
	${INSTALL_MAN} ${WRKSRC}/doc/dbz.3  ${PREFIX}/man/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrp.access.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/moderators.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrpd.8  ${PREFIX}/man/man8/

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/actived.sh ${PREFIX}/etc/rc.d/actived
	PKG_PREFIX=${PREFIX} ${SH} ${WRKDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../wip/c-news/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
