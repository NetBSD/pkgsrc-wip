# $NetBSD: Makefile,v 1.2 2008/10/23 06:01:03 phonohawk Exp $
#

DISTNAME=	css-mode
PKGNAME=	css-mode-1.0
CATEGORIES=	editors
MASTER_SITES=	http://www.brgeight.se/downloads/emacs/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.brgeight.se/
COMMENT=	CSS editing mode for Emacs

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_CONFIGURE=YES

do-build:
	cd ${WRKSRC} \
	&& ${EMACS_BIN} -batch -f batch-byte-compile css-mode.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.el  ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
