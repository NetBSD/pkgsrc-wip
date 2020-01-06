# $NetBSD$

DISTNAME=	guile-persist-${GITLAB_TAG}
PKGNAME=	guile-persist-1.0.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/tampe/${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/
GITLAB_PROJECT=	guile-persist
GITLAB_TAG=	ebebb66ae6d6c47dbc406cdbcaccb5ffed2e463a

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://gitlab.com/tampe/guile-persist/
COMMENT=	Persistance programming framework for GNU Guile
LICENSE=	gnu-lgpl-v2
USE_TOOLS+=	pkg-config

GUILE_NEED_BOOTSTRAP=	yes
GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

SUBST_CLASSES+=		ccache
SUBST_MESSAGE.ccache=	Use canonical ccache location.
SUBST_FILES.ccache=	Makefile.am
SUBST_SED.ccache=	-e 's,site-ccache,ccache,g'
SUBST_STAGE.ccache=	post-patch

# \xxx: Upstream is not responsive on merging this.
# https://gitlab.com/tampe/guile-persist/merge_requests/1
SUBST_CLASSES+=			portability
SUBST_MESSAGE.portability=	Fix portability issues
SUBST_FILES.portability=	configure.ac
SUBST_SED.portability=		-e 's,==,=,g'
SUBST_STAGE.portability=	post-patch

SUBST_CLASSES+=		makefile
SUBST_MESSAGE.makefile=	Use directories from Guile prefix.
SUBST_FILES.makefile=	src/Makefile.am
SUBST_SED.makefile=	-e "s,usr/local/lib,${PREFIX}/guile/2.2/lib,g"
SUBST_SED.makefile+=	-e "s,usr/local/include,${PREFIX}/guile/2.2/include,g"
SUBST_STAGE.makefile=	post-patch

# pre-configure is already used via module.mk, this folder needs to be
# created before the rule in pre-configure runs.
post-extract:
	cd ${WRKSRC} && mkdir m4

.include "../../lang/guile22/module.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
