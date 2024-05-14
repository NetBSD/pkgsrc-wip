# $NetBSD$

DISTNAME=	aligrudi-neatroff_make
PKGNAME=	neatroff-20231125
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}
GITHUB_PROJECT=	neatroff_make
GITHUB_TAG=	7cf23e411527a8e85c6fda689523f90b5f03a235

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/aligrudi/neatroff
COMMENT=	Clone of the Troff typesetting system
LICENSE=	isc AND mit

GITHUB_SUBMODULES+=	aligrudi neatroff 42ffa05d4aca7941be9d9b90c5d243b69521dd61 neatroff

DEPENDS+=		neatpost-[0-9]*:../../wip/neatpost
DEPENDS+=		urw-fonts-[0-9]*:../../fonts/urw-fonts
TOOL_DEPENDS+=		neatmkfn-[0-9]*:../../wip/neatmkfn

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'
SUBST_FILES.path=	man/neatroff.1

BUILD_DIRS=		neatroff

MAKE_FLAGS+=		FDIR=${PREFIX}/share/neatroff
MAKE_FLAGS+=		MDIR=${PREFIX}/share/neatroff/tmac

post-build:
	${PREFIX}/share/neatroff/gen.sh ${PREFIX}/share/fonts/urw	\
		${WRKSRC}/devutf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/neatroff/tmac/me
INSTALLATION_DIRS+=	share/neatroff/devutf

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

.include "../../mk/bsd.pkg.mk"
