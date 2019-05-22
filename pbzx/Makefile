# $NetBSD$

DISTNAME=	pbzx-1.0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=NiklasRosenstein/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NiklasRosenstein/pbzx
COMMENT=	Tool to extract Apple PBZX-compressed files
LICENSE=	gnu-gpl-v3

# Might work for other platforms, but they'd need libxar.so
ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=	c

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/doc/${PKGBASE}


do-build:
	cd ${WRKSRC} && \
		${MAKE_ENV} ${CC} ${CFLAGS} ${LDFLAGS} \
			-llzma -lxar pbzx.c -o pbzx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
