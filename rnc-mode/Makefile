# $NetBSD: Makefile,v 1.3 2012/10/07 14:23:56 asau Exp $
#

DISTNAME=	RncMode-1_0b3
PKGNAME=	rnc-mode-1.0b3
CATEGORIES=	editors
MASTER_SITES=	http://www.pantor.com/
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.pantor.com/download.html
COMMENT=	Emacs mode for editing compact RELAX NG schemas

USE_LANGUAGES=	# none

NO_CONFIGURE=	YES

do-build:
	cd ${WRKSRC} \
	&& ${EMACS_BIN} -batch -f batch-byte-compile rnc-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
