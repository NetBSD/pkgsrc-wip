# $NetBSD: Makefile,v 1.4 2009/07/31 22:18:51 minskim Exp $
#

DISTNAME=	php-mode-1.1.0
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=php-mode/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dmb@except.one.pl
HOMEPAGE=	http://php-mode.sourceforge.net/
COMMENT=	PHP editing mode for Emacs

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}

.include "../../editors/emacs/modules.mk"

do-build:
	cd ${WRKSRC}; \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
			-l php-mode.el -f batch-byte-compile php-mode.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/php-mode
	cd ${WRKSRC}; \
		${INSTALL_DATA} php-mode.el php-mode.elc \
			${EMACS_LISPPREFIX}/php-mode

.include "../../mk/bsd.pkg.mk"
