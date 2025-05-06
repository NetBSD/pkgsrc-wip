# $NetBSD$

DISTNAME=	powerlevel10k-1.20.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=romkatv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES+=	${DEFAULT_DISTFILES} libgit2-${LIBGIT2_VERSION}.tar.gz
SITES.libgit2-${LIBGIT2_VERSION}.tar.gz= -${MASTER_SITE_GITHUB:=romkatv/}libgit2/archive/${LIBGIT2_VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romkatv/powerlevel10k/
COMMENT=	Fast and flexible Theme for zsh with good defaults
LICENSE=	mit

# build system uses cmake for included libgit2 version, but is something else
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	zsh-[0-9]*:../../shells/zsh

# own hacked version of libgit2
EXTRACT_ONLY=		${DEFAULT_DISTFILES}
LIBGIT2_VERSION=	tag-2ecf33948a4df9ef45a66c68b8ef24a5e60eaac6

USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake git pax

INSTALLATION_DIRS+=	share/zsh-powerlevel10k
INSTALLATION_DIRS+=	share/zsh-powerlevel10k/config
INSTALLATION_DIRS+=	share/zsh-powerlevel10k/internal

# builds libgit2 inside this tmp directory, needs to be inside WRKDIR because of buildlink3
MAKE_ENV+=	TMPDIR=${WRKDIR}/tmp

pre-configure:
	cp ${DISTDIR}/libgit2-${LIBGIT2_VERSION}.tar.gz ${WRKSRC}/gitstatus/deps
	mkdir ${WRKDIR}/tmp

do-build:
	cd ${WRKSRC}/gitstatus && ${MAKE_ENV} ${PKGSRC_MAKE_ENV} ./build

do-install:
	${INSTALL_DATA} ${WRKSRC}/powerlevel10k.zsh-theme ${DESTDIR}${PREFIX}/share/zsh-powerlevel10k
	${INSTALL_DATA} ${WRKSRC}/powerlevel9k.zsh-theme ${DESTDIR}${PREFIX}/share/zsh-powerlevel10k
	${INSTALL_DATA} ${WRKSRC}/config/* ${DESTDIR}${PREFIX}/share/zsh-powerlevel10k/config
	${INSTALL_DATA} ${WRKSRC}/internal/* ${DESTDIR}${PREFIX}/share/zsh-powerlevel10k/internal
	cd ${WRKSRC}/gitstatus && ${PAX} -pp -rw build.info install usrbin *sh ${DESTDIR}${PREFIX}/share/zsh-powerlevel10k/gitstatus

#.include "../../devel/pcre/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
