# $NetBSD: Makefile,v 1.2 2009/07/31 22:18:51 minskim Exp $
#

DISTNAME=	mpc.el-p29
PKGNAME=	mpc-el-29
CATEGORIES=	audio
MASTER_SITES=	http://www.iro.umontreal.ca/~monnier/elisp/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.iro.umontreal.ca/~monnier/elisp/#mpc.el
COMMENT=	Emacs front end to the Music Player Daemon

USE_TOOLS+=	gmake

MESSAGE_SUBST+=         LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} && \
		rm -f *.elc *-autoloads.el && \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		EMACS=${EMACS_BIN} \
		all

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mpc
	${INSTALL_DATA} ${WRKSRC}/*.el  ${EMACS_LISPPREFIX}/mpc
	${INSTALL_DATA} ${WRKSRC}/*.elc ${EMACS_LISPPREFIX}/mpc

	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mpc/images/mpc
	${INSTALL_DATA} ${WRKSRC}/images/mpc/*.xpm ${EMACS_LISPPREFIX}/mpc/images/mpc

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
