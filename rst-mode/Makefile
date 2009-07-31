# $NetBSD: Makefile,v 1.3 2009/07/31 22:18:51 minskim Exp $
#

DISTNAME=	rst
PKGNAME=	rst-mode-0.6
CATEGORIES=	editors
MASTER_SITES=	http://docutils.sourceforge.net/tools/editors/emacs/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://docutils.sourceforge.net/docs/user/emacs.html
COMMENT=	Emacs mode for reStructuredText documents

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT= user-destdir

NO_CONFIGURE=YES

do-build:
	cd ${WRKSRC} \
	&& ${EMACS_BIN} -batch -f batch-byte-compile rst.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
