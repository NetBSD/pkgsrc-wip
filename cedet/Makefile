# $NetBSD: Makefile,v 1.1.1.1 2008/07/16 04:52:08 phonohawk Exp $
#

DISTNAME=	cedet-1.0pre4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cedet.sourceforge.net/
COMMENT=	Collection of Emacs Development Environment Tools

MESSAGE_SUBST+=         LISPDIR=${EMACS_LISPPREFIX:Q}

USE_TOOLS=	gmake
INFO_FILES=     yes

MAKE_FLAGS+=	EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=	base

do-build:
	cd ${WRKSRC} \
        && ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
                EMACS=${EMACS_BIN}

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/semantic/semanticdb.sh ${PREFIX}/bin

.for pkg in cogre common contrib ede eieio semantic semantic/bovine semantic/wisent speedbar
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/cedet/${pkg}
	${INSTALL_DATA} ${WRKSRC}/${pkg}/Project.ede ${EMACS_LISPPREFIX}/cedet/${pkg}
	${INSTALL_DATA} ${WRKSRC}/${pkg}/*.el ${EMACS_LISPPREFIX}/cedet/${pkg}
	${INSTALL_DATA} ${WRKSRC}/${pkg}/*.elc ${EMACS_LISPPREFIX}/cedet/${pkg}
.endfor

	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/cedet/common/icons
	${INSTALL_DATA} ${WRKSRC}/common/icons/Project.ede ${EMACS_LISPPREFIX}/cedet/common/icons
	${INSTALL_DATA} ${WRKSRC}/common/icons/*.xpm ${EMACS_LISPPREFIX}/cedet/common/icons

	${INSTALL_DATA_DIR} ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/*/*.info* ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/*/doc/*.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
.include "../../mk/emacs.mk"
