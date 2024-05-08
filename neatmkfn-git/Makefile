# $NetBSD$

PKGNAME=	neatmkfn-git-0
CATEGORIES=	textproc

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://litcave.rudi.ir/
COMMENT=	Neatroff font description generator
LICENSE=	isc

GIT_REPOSITORIES=	neatroff_make neatmkfn
.for repo in ${GIT_REPOSITORIES}
GIT_REPO.${repo}=	https://github.com/aligrudi/${repo}.git
GIT_BRANCH.${repo}=	master
.endfor
GIT_EXTRACTDIR.neatmkfn= 						\
	${GIT_EXTRACTDIR.neatroff_make}/neatmkfn

WRKSRC=			${WRKDIR}/${GIT_EXTRACTDIR.neatroff_make}

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_FILES.path=	man/neatmkfn.1 neatmkfn/gen.sh
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'
SUBST_SED.path+=	-e 's|./mkfn|${PREFIX}/bin/neatmkfn|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/neatroff

do-build:
	cd ${WRKSRC}/neatmkfn && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatmkfn/mkfn			\
		${DESTDIR}${PREFIX}/bin/neatmkfn
	${INSTALL_MAN} ${WRKSRC}/man/neatmkfn.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/neatmkfn/gen.sh			\
		${DESTDIR}${PREFIX}/share/neatroff

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
