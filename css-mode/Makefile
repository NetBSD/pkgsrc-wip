# $NetBSD: Makefile,v 1.1.1.1 2008/10/23 05:19:31 phonohawk Exp $
#

DISTNAME=	css-mode
PKGNAME=	css-mode-0.11
CATEGORIES=	editors
MASTER_SITES=	http://www.garshol.priv.no/download/software/css-mode/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.garshol.priv.no/download/software/css-mode/
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
