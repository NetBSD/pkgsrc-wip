# $NetBSD$

VERSION=	4.1.3
DISTNAME=	magit-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magit/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/
COMMENT=	Emacs client for scm Git
LICENSE=	gnu-gpl-v3

# (still getting) (still getting) makeinfo: unknown option -- css-ref
DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

#MAKE_ENV+=	MANUAL_HTML_ARGS=
#MAKE_ENV+=	-DPREFIX=${PREFIX}
#MAKE_ENV+=	-DDASH_DIR=${PREFIX}/share/emacs/site-lisp/dash
#MAKE_ENV+=	-DINSTALL_INFO=install-info

SUBST_CLASSES+=		lisp
SUBST_FILES.lisp=	default.mk
SUBST_STAGE.lisp=	pre-build
SUBST_SED.lisp=		-e s.@@PREFIX@@.${PREFIX}.

NO_CONFIGURE=	yes
USE_LANGUAGES=	#
USE_TOOLS+=	gmake makeinfo
MAKE_JOBS_SAFE=	no

.include "../../editors/emacs/modules.mk"

#INFO_FILES=	yes
#UILD_TARGET=	lisp
TEST_TARGET=	check

.include "../../wip/dash-el/buildlink3.mk"
.include "../../wip/with-editor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
