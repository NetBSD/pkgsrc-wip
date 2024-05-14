# $NetBSD$

DISTNAME=	aligrudi-neatroff_make
PKGNAME=	neatpost-20230617
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}
GITHUB_PROJECT=	neatroff_make
GITHUB_TAG=	7cf23e411527a8e85c6fda689523f90b5f03a235

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/aligrudi/neatpost
COMMENT=	Neatroff PS/PDF postprocessor
LICENSE=	isc

GITHUB_SUBMODULES+=	aligrudi neatpost d95ce8a3ae061634ae77b959b5dc08af78ca066d neatpost

SUBST_CLASSES=		path
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	post-build
SUBST_SED.path=		-e 's|/usr/share|${PREFIX}/share|g'
SUBST_FILES.path=	man/neatpost.1

BUILD_DIRS=		neatpost

MAKE_FLAGS+=		FDIR=${PREFIX}/share/neatroff
MAKE_FLAGS+=		MDIR=${PREFIX}/share/neatroff/tmac

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatpost/post			\
		${DESTDIR}${PREFIX}/bin/neatpost-ps
	${INSTALL_PROGRAM} ${WRKSRC}/neatpost/pdf			\
		${DESTDIR}${PREFIX}/bin/neatpost-pdf
	${INSTALL_MAN} ${WRKSRC}/man/neatpost.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
