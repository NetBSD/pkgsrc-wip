# $NetBSD: Makefile,v 1.16 2006/05/14 09:41:37 scode Exp $
#

DISTNAME=	pkgmanager-${PKGMGR_VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	http://starfury.scode.org/pkgmanager/
DISTFILES+=	pkgmanager-${PKGMGR_VERSION:Q}.tar.gz
DISTFILES+=	clocc-06-24-05.tgz
DISTFILES+=	cl-ppcre-${PPCRE_VERSION:Q}.tar.gz

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://www.scode.org/pkgmanager/
COMMENT=	Package manager for pkgsrc

WRKSRC=		${WRKDIR}
PKGMGR_VERSION=	0.8.0
PPCRE_VERSION=	1.2.10

USE_TOOLS+=	gmake
DEPENDS+=	clisp>=2.33.2nb1:../../lang/clisp
DEPENDS+=	pkg_tarup>=1.6.5:../../pkgtools/pkg_tarup

CLISP=		${PREFIX}/bin/clisp
PKGMGR_SRC=	${WRKDIR}/pkgmanager-${PKGMGR_VERSION}/src
PKGMGR_LIBDIR=	${PREFIX}/lib/pkgmanager
PKGMGR_BINDIR=	${PREFIX}/bin
SUBST_CLASSES+=		clocc
SUBST_STAGE.clocc=	post-patch
SUBST_FILES.clocc=	clocc/clocc.lisp
SUBST_SED.clocc=	-e "s|/usr/local/src/clocc/|${WRKDIR}/clocc/|g"
SUBST_MESSAGE.clocc=	Fixing clocc root directory in clocc.lisp

SUBST_CLASSES+=		wrapper
SUBST_STAGE.wrapper=	post-patch
SUBST_FILES.wrapper=	pkgmanager-${PKGMGR_VERSION:Q}/src/pkgmanager-wrapper.sh
SUBST_SED.wrapper=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.wrapper+=	-e "s|@MAKE@|${MAKE}|g"
SUBST_SED.wrapper+=	-e "s|@DBDIR@|${PKG_DBDIR}|g"
SUBST_MESSAGE.wrapper=	Fixing prefix in pkgmanager shell script wrapper

SUBST_CLASSES+=		runner
SUBST_STAGE.runner=	post-patch
SUBST_FILES.runner=	pkgmanager-${PKGMGR_VERSION:Q}/src/run.lisp
SUBST_SED.runner=	-e "s|\*base-dir\* \\\"\.\\\"|\*base-dir\* \
				\\\"${PREFIX}/lib/pkgmanager\\\"|g"
SUBST_MESSAGE.runner=	Fixing load base in runner

post-extract:
	${CHMOD} +x ${WRKDIR}/pkgmanager-${PKGMGR_VERSION:Q}/src/prepclocc.sh

.PHONY: prepare-clocc
prepare-clocc:
	${WRKDIR}/pkgmanager-${PKGMGR_VERSION:Q}/src/prepclocc.sh ${WRKDIR}/clocc

do-build: prepare-clocc
	${CLISP} -K full ${WRKDIR}/pkgmanager-${PKGMGR_VERSION:Q}/src/prepimage.lisp \
		${WRKDIR}/init.mem \
		${WRKDIR}/clocc/ \
		${WRKDIR}/cl-ppcre-${PPCRE_VERSION:Q}/
	${CLISP} -K full -M ${WRKDIR}/init.mem \
		${PKGMGR_SRC:Q}/compile-all.lisp ${PKGMGR_SRC:Q}

do-install:
	${INSTALL_DATA_DIR} /etc/pkgmanager/
	${INSTALL_DATA_DIR} ${PKGMGR_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/init.mem ${PKGMGR_LIBDIR}/init.mem
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/run.lisp ${PKGMGR_LIBDIR}/run.lisp
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/packages.fas ${PKGMGR_LIBDIR}/packages.fas
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/pkgmgr-except.fas ${PKGMGR_LIBDIR}/pkgmgr-except.fas
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/pkgmgr-print.fas ${PKGMGR_LIBDIR}/pkgmgr-print.fas
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/pkgmgr-util.fas ${PKGMGR_LIBDIR}/pkgmgr-util.fas
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/pkgmgr-pkgdb.fas ${PKGMGR_LIBDIR}/pkgmgr-pkgdb.fas
	${INSTALL_DATA} ${PKGMGR_SRC:Q}/pkgmanager.fas ${PKGMGR_LIBDIR}/pkgmanager.fas
	${INSTALL_SCRIPT} ${PKGMGR_SRC:Q}/pkgmanager-wrapper.sh \
		${PKGMGR_BINDIR}/pkgmanager
	${INSTALL_MAN} ${PKGMGR_SRC:Q}/pkgmanager.1 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
