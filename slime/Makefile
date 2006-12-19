# $NetBSD: Makefile,v 1.1.1.1 2006/12/19 07:35:40 netcap Exp $
#

DISTNAME=	slime-2.0
CATEGORIES=	editors
MASTER_SITES=	http://common-lisp.net/project/slime/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://common-lisp.net/project/slime/
COMMENT=	Superior Lisp Interaction Mode for Emacs

USE_TOOLS+=	gmake makeinfo
NO_CONFIGURE=	yes

INSTALLATION_DIRS=      ${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/slime
SLIME_LISPDIR=  ${EMACS_LISPPREFIX}/slime

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_BIN} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

pre-install:
	${MKDIR} ${SLIME_LISPDIR}

do-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} ChangeLog ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.el ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.elc ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.lisp ${SLIME_LISPDIR}
		${INSTALL_DATA} ${WRKSRC}/doc/slime.info ${EMACS_INFOPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
