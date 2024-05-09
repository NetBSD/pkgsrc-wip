# $NetBSD$

PKGNAME=	neatroff-git-0
CATEGORIES=	textproc

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://litcave.rudi.ir/
COMMENT=	Neatroff clone of the Troff typesetting system
LICENSE=	isc AND mit

GIT_REPOSITORIES=	neatroff_make neatroff
.for repo in ${GIT_REPOSITORIES}
GIT_REPO.${repo}=	https://github.com/aligrudi/${repo}.git
GIT_BRANCH.${repo}=	master
.endfor
GIT_EXTRACTDIR.neatroff= 						\
	${GIT_EXTRACTDIR.neatroff_make}/neatroff

WRKSRC=			${WRKDIR}/${GIT_EXTRACTDIR.neatroff_make}

DEPENDS+=		neatpost-git-[0-9]*:../../wip/neatpost-git
DEPENDS+=		urw-fonts-[0-9]*:../../fonts/urw-fonts
TOOL_DEPENDS+=		neatmkfn-git-[0-9]*:../../wip/neatmkfn-git

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_FILES.path=	man/neatroff.1
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/neatroff/tmac share/neatroff/tmac/me
INSTALLATION_DIRS+=	share/neatroff/devutf

do-build:
	cd ${WRKSRC}/neatroff && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		FDIR=${PREFIX}/share/neatroff				\
		MDIR=${PREFIX}/share/neatroff/tmac
	${PREFIX}/share/neatroff/gen.sh ${PREFIX}/share/fonts/urw	\
		${WRKSRC}/devutf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatroff/roff			\
		${DESTDIR}${PREFIX}/bin/neatroff
	${INSTALL_MAN} ${WRKSRC}/man/neatroff.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/tmac/strings.mm			\
		${DESTDIR}${PREFIX}/share/neatroff/tmac
	${INSTALL_DATA} ${WRKSRC}/tmac/tmac.*				\
		${DESTDIR}${PREFIX}/share/neatroff/tmac
	${INSTALL_DATA} ${WRKSRC}/tmac/me/*.me				\
		${DESTDIR}${PREFIX}/share/neatroff/tmac/me
	${INSTALL_DATA} ${WRKSRC}/devutf/*				\
		${DESTDIR}${PREFIX}/share/neatroff/devutf

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
