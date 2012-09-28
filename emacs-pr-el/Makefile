# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:32 asau Exp $

DISTNAME=		emacs-pr-el-0.0.1
CATEGORIES=		misc
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		#
COMMENT=		Modified version of GNATS send-pr.el

NO_CHECKSUM=		yes

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
DEPENDS+=		send-pr-[0-9]*:../../wip/send-pr
GNATS_DATADIR=		${PREFIX}/share
.else
GNATS_DATADIR=		/usr/share
.endif

GNATS_SUBMITTER?=	net

SUBST_CLASSES+=		send-pr
SUBST_STAGE.send-pr=	post-extract
SUBST_MESSAGE.send-pr=	Configuring emacs-pr.el
SUBST_FILES.send-pr=	emacs-pr.el
SUBST_SED.send-pr=	-e 's,xDATADIRx,${GNATS_DATADIR},g'
SUBST_SED.send-pr+=	-e 's,xGNATS_ROOTx,,g'
SUBST_SED.send-pr+=	-e 's,xVERSIONx,3.95,g'
SUBST_SED.send-pr+=	-e 's,xGNATS_SITEx,netbsd,g'
SUBST_SED.send-pr+=	-e 's,xDEFAULT_RELEASEx,`uname -s` `uname -r`,g'
SUBST_SED.send-pr+=	-e 's,xSUBMITTERx,${GNATS_SUBMITTER},g'

SRC=			emacs-pr.el

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

do-extract:
	cp ${.CURDIR}/files/emacs-pr.el ${WRKSRC}

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch	\
		-f batch-byte-compile ${WRKSRC}/${SRC}

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRC} ${SRC:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
