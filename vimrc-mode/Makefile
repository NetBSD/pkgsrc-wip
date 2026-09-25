# $NetBSD: Makefile,v 1.2 2012/10/07 17:41:42 asau Exp $

DISTNAME=	vimrc-mode-0.2.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vimrc-mode/}
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://vimrc-mode.sourceforge.net/
COMMENT=	Emacs major mode for editing .vimrc configuration files
LICENSE=	gnu-gpl-v2

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs214nox xemacs215 xemacs215nox

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

do-build:
	${RUN} cd ${WRKSRC} && \
		${CP} -f ${DISTNAME}.el vimrc-mode.el && \
		${EMACS_BIN} -batch -f batch-byte-compile vimrc-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/vimrc-mode.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/vimrc-mode.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
