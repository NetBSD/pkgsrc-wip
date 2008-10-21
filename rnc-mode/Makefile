# $NetBSD: Makefile,v 1.1.1.1 2008/10/21 07:20:29 phonohawk Exp $
#

DISTNAME=	RncMode-1_0b3
PKGNAME=	rnc-mode-1.0b3
CATEGORIES=	editors
MASTER_SITES=	http://www.pantor.com/
EXTRACT_SUFX=	.tgz
WRKSRC=			${WRKDIR}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.pantor.com/download.html
COMMENT=	Emacs mode for editing compact RELAX NG schemas

USE_LANGUAGES=	# none

NO_CONFIGURE=YES

do-build:
	cd ${WRKSRC} \
	&& ${EMACS_BIN} -batch -f batch-byte-compile rnc-mode.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.el  ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
