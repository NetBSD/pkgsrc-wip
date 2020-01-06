# $NetBSD$

DISTNAME=	stis-parser-${GITLAB_TAG}
PKGNAME=	guile-stis-parser-0.0.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/tampe/${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/
GITLAB_PROJECT=	stis-parser
GITLAB_TAG=	5d91e9ee8ebf7e7c5911f5689a92ece954aa3f82

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://gitlab.com/tampe/stis-parser/
COMMENT=		Parser combinator framework for GNU Guile
LICENSE=		gnu-lgpl-v2
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes

WRKSRC=			${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}/modules

SUBST_CLASSES+=		ccache
SUBST_MESSAGE.ccache=	Use canonical ccache location.
SUBST_FILES.ccache=	Makefile.am
SUBST_SED.ccache=	-e 's/\/site-ccache/\/ccache/g'
SUBST_STAGE.ccache=	post-patch

# pre-configure misses creation of m4 directory which is missing in
# the source.
post-extract:
	cd ${WRKSRC} && mkdir m4

.include "../../lang/guile22/module.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
