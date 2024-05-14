# $NetBSD$

DISTNAME=	aligrudi-neatroff_make
PKGNAME=	neatmkfn-20231029
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}
GITHUB_PROJECT=	neatroff_make
GITHUB_TAG=	7cf23e411527a8e85c6fda689523f90b5f03a235

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/aligrudi/neatmkfn
COMMENT=	Neatroff font description generator
LICENSE=	isc

GITHUB_SUBMODULES+=	aligrudi neatmkfn c0a552e29e9502fe47191153234ac5bdcd187b57 neatmkfn

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'
SUBST_SED.path+=	-e 's|./mkfn|${PREFIX}/bin/neatmkfn|g'
SUBST_FILES.path=	man/neatmkfn.1 neatmkfn/gen.sh

BUILD_DIRS=		neatmkfn

MAKE_FLAGS+=		FDIR=${PREFIX}/share/neatroff
MAKE_FLAGS+=		MDIR=${PREFIX}/share/neatroff/tmac

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/neatroff

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatmkfn/mkfn			\
		${DESTDIR}${PREFIX}/bin/neatmkfn
	${INSTALL_MAN} ${WRKSRC}/man/neatmkfn.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/neatmkfn/gen.sh			\
		${DESTDIR}${PREFIX}/share/neatroff

.include "../../mk/bsd.pkg.mk"
