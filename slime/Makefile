# $NetBSD$

DISTNAME=		slime-2.32
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=slime/}
GITHUB_PROJECT=		slime
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		https://common-lisp.net/project/slime/
COMMENT=		Superior Lisp Interaction Mode for Emacs
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND \
			mit AND public-domain AND gnu-llgpl

USE_TOOLS+=		gmake makeinfo
NO_CONFIGURE=		yes
INFO_FILES=		yes

INSTALLATION_DIRS+=	${EMACS_INFOPREFIX}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/slime
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/slime/lib
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/slime/swank

SLIME_LISPDIR=		${EMACS_LISPPREFIX}/slime

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs214nox xemacs215 xemacs215nox

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_BIN} --batch --no-init-file --no-site-lisp \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} ChangeLog ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.el ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.elc ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.lisp ${DESTDIR}${SLIME_LISPDIR}; \
		${INSTALL_DATA} swank/*.lisp ${DESTDIR}${SLIME_LISPDIR}/swank; \
		${INSTALL_DATA} lib/*.el ${DESTDIR}${SLIME_LISPDIR}/lib; \
		${INSTALL_DATA} doc/slime.info ${DESTDIR}${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
