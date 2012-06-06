# $NetBSD: Makefile,v 1.1.1.1 2012/06/06 01:44:07 phonohawk Exp $
#

DISTNAME=	vimrc-mode-0.2.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=${PKGBASE}/}
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://${PKGBASE}.sourceforge.net/
COMMENT=	Emacs major mode for editing .vimrc configuration files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

WRKSRC=	${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

do-build:
	${RUN} cd ${WRKSRC} && \
		${CP} -f ${DISTNAME}.el ${PKGBASE}.el && \
		${EMACS_BIN} -batch -f batch-byte-compile ${PKGBASE}.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
