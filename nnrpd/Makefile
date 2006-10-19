# $NetBSD: Makefile,v 1.9 2006/10/19 22:11:26 hfath Exp $

DISTNAME=		inn-1.7.2.insync-1.1d
PKGNAME=		nnrpd-1.7.2
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/OLD/1.7/ \
			ftp://ftp.sunet.se/pub/news/nntp/inn/OLD/1.7/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/OLD/1.7/

MAINTAINER=		hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=		http://www.isc.org/sw/inn/
COMMENT=		NNTP reader daemon from release 1.7 of InterNet News (INN)

INN_DATA_DIR?=		/var/news

CONFLICTS+=		nntpclnt-[0-9]* \
			inn-[1-9].*
RCD_SCRIPTS=		actived

.include "../../mk/bsd.prefs.mk"
.include "../../wip/c-news/Makefile.common"

# We need include and library paths to compile in Perl support
PERL_LDOPTS_cmd=	eval ${PERL5} -MExtUtils::Embed -e ldopts 2>/dev/null
PERL_ARCHLIB_cmd=	eval `${PERL5} -V:installarchlib 2>/dev/null`; \
			${ECHO} $${installarchlib}

# Given foo=${bar}, replace @foo@ with ${bar}.
#
FILES_SUBST=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		INNDATA=${INN_DATA_DIR:Q}
FILES_SUBST+=		INNPREFIX=${PREFIX:Q}
FILES_SUBST+=		INNMANPREFIX=${PREFIX:Q}
FILES_SUBST+=		PERL_LDOPTS="${PERL_LDOPTS_cmd:sh}"
FILES_SUBST+=		PERL_INC="-I${PERL_ARCHLIB_cmd:sh}/CORE -DPERL_POLLUTE"

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

DEINSTALL_SRC=		${WRKDIR}/DEINSTALL
INSTALL_SRC=		${WRKDIR}/INSTALL
RCD_SCRIPTS=		actived.sh

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
	${INSTALL_MAN} ${WRKSRC}/doc/dbz.3  ${PREFIX}/${PKGMANDIR}/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrp.access.5 ${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/moderators.5 ${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/nnrpd.8  ${PREFIX}/${PKGMANDIR}/man8/

.include "../../wip/c-news/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
