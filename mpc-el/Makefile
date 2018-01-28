# $NetBSD: Makefile,v 1.3 2012/10/03 14:32:32 asau Exp $
#

DISTNAME=	mpc.el-p29
PKGNAME=	mpc-el-29
CATEGORIES=	audio
MASTER_SITES=	http://www.iro.umontreal.ca/~monnier/elisp/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.iro.umontreal.ca/~monnier/elisp/#mpc.el
COMMENT=	Emacs front end to the Music Player Daemon

USE_TOOLS+=	gmake

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} && \
		rm -f *.elc *-autoloads.el && \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		EMACS=${EMACS_BIN} \
		all

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/mpc
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}/mpc
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/mpc

	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/mpc/images/mpc
	${INSTALL_DATA} ${WRKSRC}/images/mpc/*.xpm ${DESTDIR}${EMACS_LISPPREFIX}/mpc/images/mpc

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
