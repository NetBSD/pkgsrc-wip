# $NetBSD$

DISTNAME=	compat-30.0.1.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=emacs-compat/}
GITHUB_PROJECT=	compat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/with-editor/
COMMENT=
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=		yes
USE_LANGUAGES=		#
USE_TOOLS+=		gmake makeinfo

TEST_TARGET=		check
INSTALL_TARGET=		#
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/compat
AUTO_MKDIRS=		yes

MAKE_FLAGS+=		EMACS=${EMACS_BIN}

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 # dash-el
# hangs
EMACS_VERSIONS_INCOMPATIBLE+=	xemacs214 xemacs215 xemacs214nox xemacs215nox

do-install:
	( cd ${WRKSRC} ; \
	for i in *el *.elc COPYING README* ; do  \
	${INSTALL_DATA}  $$i ${DESTDIR}/${EMACS_LISPPREFIX}/compat  ; \
	done \
	)

.include "../../editors/emacs/modules.mk"
.include "../../wip/dash-el/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
