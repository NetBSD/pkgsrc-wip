# $NetBSD$

VERSION=	3.4.3
DISTNAME=	with-editor-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magit/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/with-editor/
COMMENT=
LICENSE=	gnu-gpl-v3

# (still getting) (still getting) makeinfo: unknown option -- css-ref
DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

MAKE_ENV=	MANUAL_HTML_ARGS=

NO_CONFIGURE=	yes
USE_LANGUAGES=	#
USE_TOOLS+=	gmake makeinfo
MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=         lisp
SUBST_FILES.lisp=       default.mk
SUBST_STAGE.lisp=       pre-build
SUBST_SED.lisp=         -e s.@@PREFIX@@.${PREFIX}.

.include "../../editors/emacs/modules.mk"

#INFO_FILES=		yes
#UILD_TARGET=		all
TEST_TARGET=		check
INSTALL_TARGET=		#
INSTALLATION_DIRS=	${PREFIX}/share/emacs/site-lisp/with-editor
AUTO_MKDIRS=		yes

do-install:
	( cd ${WRKSRC} ; \
	${INSTALL_DATA} lisp/with-editor-autoloads.el ${DESTDIR}${INSTALLATION_DIRS} ; \
	${INSTALL_DATA} lisp/with-editor.el           ${DESTDIR}${INSTALLATION_DIRS} ; \
	${INSTALL_DATA} lisp/with-editor.elc          ${DESTDIR}${INSTALLATION_DIRS} ; \
	)

.include "../../wip/emacs-compat/buildlink3.mk"
.include "../../wip/dash-el/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
