# $NetBSD$

PKGNAME=	neatpost-git-0
CATEGORIES=	textproc

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://litcave.rudi.ir/
COMMENT=	Neatroff PostScript/PDF postprocessor
LICENSE=	isc

GIT_REPOSITORIES=	neatroff_make neatpost
.for repo in ${GIT_REPOSITORIES}
GIT_REPO.${repo}=	https://github.com/aligrudi/${repo}.git
GIT_BRANCH.${repo}=	master
.endfor
GIT_EXTRACTDIR.neatpost= 						\
	${GIT_EXTRACTDIR.neatroff_make}/neatpost

WRKSRC=			${WRKDIR}/${GIT_EXTRACTDIR.neatroff_make}

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_FILES.path=	man/neatpost.1
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/neatpost && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		FDIR=${PREFIX}/share/neatroff

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatpost/post			\
		${DESTDIR}${PREFIX}/bin/neatpost-ps
	${INSTALL_PROGRAM} ${WRKSRC}/neatpost/pdf			\
		${DESTDIR}${PREFIX}/bin/neatpost-pdf
	${INSTALL_MAN} ${WRKSRC}/man/neatpost.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
