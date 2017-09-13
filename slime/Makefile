# $NetBSD: Makefile,v 1.8 2014/04/06 23:57:44 othyro Exp $
#

DISTNAME=		v${PKGVER}
PKGVER=			2.5
PKGNAME=		${EMACS_PKGNAME_PREFIX}slime-${PKGVER}
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		https://github.com/slime/slime/archive/
DIST_SUBDIR=		${PKGBASE}

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://common-lisp.net/project/slime/
COMMENT=		Superior Lisp Interaction Mode for Emacs
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND mit AND public-domain # AND LLGPL

WRKSRC=			${WRKDIR}/slime-${PKGVER}
USE_TOOLS+=		gmake makeinfo
NO_CONFIGURE=		yes
INFO_FILES=		yes

INSTALLATION_DIRS+=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/slime/lib
SLIME_LISPDIR=		${EMACS_LISPPREFIX}/slime

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_BIN} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

pre-install:
	${MKDIR} ${SLIME_LISPDIR}

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} ChangeLog ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.el ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.elc ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.lisp ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} lib/*.el ${DESTDIR}${SLIME_LISPDIR}/lib
		${INSTALL_DATA} ${WRKSRC}/doc/slime.info \
			${DESTDIR}${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
