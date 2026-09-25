# $NetBSD$

VERSION=	4.1.3
DISTNAME=	magit-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magit/}
GITHUB_TAG=	v${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/
COMMENT=	Emacs client for scm Git
LICENSE=	gnu-gpl-v3

# (still getting) (still getting) makeinfo: unknown option -- css-ref
DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

MAKE_FLAGS+=	MANUAL_HTML_ARGS=
MAKE_FLAGS+=	INSTALL_INFO=install-info
MAKE_FLAGS+=	COMPAT_DIR=${EMACS_LISPPREFIX}/compat
MAKE_FLAGS+=	DASH_DIR=${EMACS_LISPPREFIX}/dash
MAKE_FLAGS+=	TRANSIENT_DIR=${EMACS_LISPPREFIX}/transient
MAKE_FLAGS+=	WITH_EDITOR_DIR=${EMACS_LISPPREFIX}/with-editor
MAKE_FLAGS+=	lispdir=${EMACS_LISPPREFIX}/magit

SUBST_CLASSES+=		batch
SUBST_FILES.batch=	default.mk lisp/Makefile test/Makefile
SUBST_STAGE.batch=	pre-build
SUBST_MESSAGE.batch=	Avoid conflict variable BATCH with pbulk
SUBST_SED.batch=	-e s.BATCH.BATCH2.

NO_CONFIGURE=	yes
USE_LANGUAGES=	#
USE_TOOLS+=	gmake makeinfo
MAKE_JOBS_SAFE=	no

EMACS_VERSIONS_ACCEPTED=	emacs30

.include "../../editors/emacs/modules.mk"

#INFO_FILES=	yes
#UILD_TARGET=	lisp
TEST_TARGET=	check

.include "../../wip/dash-el/buildlink3.mk"
.include "../../wip/emacs-compat/buildlink3.mk"
.include "../../wip/transient/buildlink3.mk"
.include "../../wip/with-editor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
