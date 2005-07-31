# $NetBSD: Makefile,v 1.1.1.1 2005/07/31 16:30:54 scode Exp $
#

PKGMGR_VERSION= 0.1.0
DISTNAME=	pkgmanager-${PKGMGR_VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	http://starfury.scode.org/pkgmanager/
PPCRE_VERSION=  1.2.10
DISTFILES+=     pkgmanager-${PKGMGR_VERSION}.tar.gz
DISTFILES+=     clocc-06-24-05.tgz
DISTFILES+=     cl-ppcre-${PPCRE_VERSION}.tar.gz
WRKSRC=         ${WRKDIR}

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://www.scode.org/pkgmanager/
COMMENT=	Package manager for pkgsrc

DEPENDS+=       clisp>=2.33.2:../../lang/clisp
BUILD_DEPENDS+=	gmake>=2.80:../../devel/gmake

CLISP=          ${PREFIX}/bin/clisp
PKGMGR_SRC=     ${WRKDIR}/pkgmanager-${PKGMGR_VERSION}/src

SUBST_CLASSES+=		clocc
SUBST_STAGE.clocc=	post-patch
SUBST_FILES.clocc=	clocc/clocc.lisp
SUBST_SED.clocc=	-e "s|/usr/local/src/clocc/|${WRKDIR}/clocc/|g"
SUBST_MESSAGE.clocc=	"Fixing clocc root directory in clocc.lisp"

SUBST_CLASSES+=         wrapper
SUBST_STAGE.wrapper= 	post-patch
SUBST_FILES.wrapper=	pkgmanager-${PKGMGR_VERSION}/src/pkgmanager-wrapper.sh
SUBST_SED.wrapper=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.wrapper=	"Fixing prefix in pkgmanager shell script wrapper"

SUBST_CLASSES+=		runner
SUBST_STAGE.runner=	post-patch
SUBST_FILES.runner=	pkgmanager-${PKGMGR_VERSION}/src/run.lisp
SUBST_SED.runner=	-e "s|\*base-dir\* \\\"\.\\\"|\*base-dir\* \\\"${PREFIX}/lib/pkgmanager\\\"|g"
SUBST_MESSAGE.runner=	"Fixing load base in runner"

post-extract:
	${CHMOD} +x ${WRKDIR}/pkgmanager-${PKGMGR_VERSION}/src/prepclocc.sh

prepare-clocc:
	${WRKDIR}/pkgmanager-${PKGMGR_VERSION}/src/prepclocc.sh ${WRKDIR}/clocc

do-build: prepare-clocc
	${CLISP} -K full ${WRKDIR}/pkgmanager-${PKGMGR_VERSION}/src/prepimage.lisp \
		${WRKDIR}/init.mem \
		${WRKDIR}/clocc/ \
		${WRKDIR}/cl-ppcre-${PPCRE_VERSION}/
	${CLISP} -K full -M ${WRKDIR}/init.mem -c ${PKGMGR_SRC}/packages.lisp \
	                                          ${PKGMGR_SRC}/pkgmanager.lisp

do-install:
	${MKDIR} -p /etc/pkgmanager/
	${MKDIR} -p ${PREFIX}/lib/pkgmanager/
	${INSTALL} -o root -g wheel ${WRKDIR}/init.mem ${PREFIX}/lib/pkgmanager/init.mem
	${INSTALL} -o root -g wheel ${PKGMGR_SRC}/run.lisp ${PREFIX}/lib/pkgmanager/run.lisp
	${INSTALL} -o root -g wheel ${PKGMGR_SRC}/packages.fas ${PREFIX}/lib/pkgmanager/packages.fas
	${INSTALL} -o root -g wheel ${PKGMGR_SRC}/pkgmanager.fas ${PREFIX}/lib/pkgmanager/pkgmanager.fas
	${INSTALL} -o root -g wheel ${PKGMGR_SRC}/pkgmanager-wrapper.sh ${PREFIX}/bin/pkgmanager

.include "../../mk/bsd.pkg.mk"
