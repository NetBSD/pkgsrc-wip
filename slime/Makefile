# $NetBSD: Makefile,v 1.6 2012/10/07 15:23:39 asau Exp $
#

DISTNAME=		slime-2.0
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		editors
MASTER_SITES=		http://common-lisp.net/project/slime/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://common-lisp.net/project/slime/
COMMENT=		Superior Lisp Interaction Mode for Emacs

USE_TOOLS+=		gmake makeinfo
NO_CONFIGURE=		yes
INFO_FILES=		yes

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/slime
SLIME_LISPDIR=		${EMACS_LISPPREFIX}/slime

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_BIN} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

pre-install:
	${MKDIR} ${SLIME_LISPDIR}

do-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} ChangeLog ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.el ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.elc ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.lisp ${DESTDIR}${SLIME_LISPDIR}
		${INSTALL_DATA} ${WRKSRC}/doc/slime.info ${DESTDIR}${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
