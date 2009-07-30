# $NetBSD: Makefile,v 1.1.1.1 2009/07/30 05:49:12 phonohawk Exp $
#

DISTNAME=	rst-mode
PKGNAME=	${DISTNAME}-0.2.9
CATEGORIES=	editors
MASTER_SITES=	http://www.merten-home.de/FreeSoftware/rst-mode/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.merten-home.de/FreeSoftware/rst-mode/
COMMENT=	Emacs mode for reStructuredText documents

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT= user-destdir

NO_CONFIGURE=YES

do-build:
	cd ${WRKSRC} \
	&& ${EMACS_BIN} -batch -f batch-byte-compile rst-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
