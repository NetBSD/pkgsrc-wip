# $NetBSD: Makefile,v 1.2 2009/07/31 22:18:50 minskim Exp $
#

DISTNAME=	ecb-2.32
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ecb/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://ecb.sourceforge.net/
COMMENT=	Emacs Code Browser

USE_TOOLS=      gmake
INFO_FILES=	yes

MESSAGE_SUBST+=         LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} \
	&& ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		EMACS=${EMACS_BIN} \
		CEDET=${EMACS_LISPPREFIX}/cedet

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ecb
	${INSTALL_DATA} ${WRKSRC}/*.el  ${EMACS_LISPPREFIX}/ecb
	${INSTALL_DATA} ${WRKSRC}/*.elc ${EMACS_LISPPREFIX}/ecb

	${INSTALL_DATA_DIR} ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/info-help/ecb.info* ${PREFIX}/info

DEPENDS+=	cedet-[0-9]*:../../wip/cedet

.include "../../mk/bsd.pkg.mk"
.include "../../editors/emacs/modules.mk"
