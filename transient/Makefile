# $NetBSD$

VERSION=	0.8.1
DISTNAME=	transient-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magit/}
GITHUB_TAG=	v${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/
COMMENT=
LICENSE=	gnu-gpl-v3

#AKE_ENV=	MANUAL_HTML_ARGS=

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake makeinfo
#MAKE_JOBS_SAFE=	no

EMACS_VERSIONS_INCOMPATIBLE=    emacs20 emacs29 emacs29nox xemacs214 xemacs215 xemacs214nox xemacs215nox

#INFO_FILES=		yes
#UILD_TARGET=		all
TEST_TARGET=		check
INSTALL_TARGET=		#
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/transient
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		lisp
SUBST_FILES.lisp=	default.mk
SUBST_STAGE.lisp=	pre-build
SUBST_SED.lisp=		-e s.@@PREFIX@@.${PREFIX}.

do-install:
	( cd ${WRKSRC}/lisp ; \
	for i in *el *.elc ; do  \
	${INSTALL_DATA}  $$i ${DESTDIR}${INSTALLATION_DIRS}  ; \
	done \
	)

.include "../../editors/emacs/modules.mk"
#include "../../wip/dash-el/buildlink3.mk"
.include "../../wip/emacs-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
