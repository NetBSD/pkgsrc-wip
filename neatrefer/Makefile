# $NetBSD$

DISTNAME=	aligrudi-neatroff_make
PKGNAME=	neatrefer-20220527
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}
GITHUB_PROJECT=	neatroff_make
GITHUB_TAG=	7cf23e411527a8e85c6fda689523f90b5f03a235

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/aligrudi/neatrefer
COMMENT=	Neatroff preprocessor for bibliographic references
LICENSE=	isc

GITHUB_SUBMODULES+=	aligrudi neatrefer 0cc4ee1f7206ea0b9218d2ce798ea50344b537f4 neatrefer

BUILD_DIRS=		neatrefer

MAKE_FLAGS+=		FDIR=${PREFIX}/share/neatroff
MAKE_FLAGS+=		MDIR=${PREFIX}/share/neatroff/tmac

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neatrefer/refer			\
		${DESTDIR}${PREFIX}/bin/neatrefer
	${INSTALL_MAN} ${WRKSRC}/man/neatrefer.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
