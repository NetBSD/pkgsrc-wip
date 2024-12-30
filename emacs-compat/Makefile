# $NetBSD$

DISTNAME=	compat-30.0.1.0
PKGNAME=	emacs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=emacs-compat/}
GITHUB_PROJECT=	compat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/with-editor/
COMMENT=
LICENSE=	gnu-gpl-v3

#AKE_ENV=	MANUAL_HTML_ARGS=

NO_CONFIGURE=		yes
USE_LANGUAGES=		#
USE_TOOLS+=		gmake makeinfo
#MAKE_JOBS_SAFE=	no


#INFO_FILES=		yes
#UILD_TARGET=		all
TEST_TARGET=		check
INSTALL_TARGET=		#
INSTALLATION_DIRS=	${PREFIX}/share/emacs/site-lisp/compat
AUTO_MKDIRS=		yes

do-install:
	( cd ${WRKSRC} ; \
	for i in *el *.elc COPYING README* ; do  \
	${INSTALL_DATA}  $$i ${DESTDIR}${INSTALLATION_DIRS}  ; \
	done \
	)

.include "../../editors/emacs/modules.mk"
.include "../../wip/dash-el/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
