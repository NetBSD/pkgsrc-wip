# $NetBSD$

DISTNAME=	aligrudi-neatroff_make
PKGNAME=	neateqn-20230825
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aligrudi/}
GITHUB_PROJECT=	neatroff_make
GITHUB_TAG=	7cf23e411527a8e85c6fda689523f90b5f03a235

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/aligrudi/neateqn
COMMENT=	Neatroff preprocessor for mathematical equations
LICENSE=	isc

GITHUB_SUBMODULES+=	aligrudi neateqn b03abd7bf2a4170070252898a600ea948fea39bb neateqn

BUILD_DIRS=		neateqn

MAKE_FLAGS+=		FDIR=${PREFIX}/share/neatroff
MAKE_FLAGS+=		MDIR=${PREFIX}/share/neatroff/tmac

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neateqn/eqn			\
		${DESTDIR}${PREFIX}/bin/neateqn
	${INSTALL_MAN} ${WRKSRC}/man/neateqn.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
