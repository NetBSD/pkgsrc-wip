# $NetBSD$

PKGNAME=	lizardfs-${VERSION}
VERSION=	3.10.4
CATEGORIES=	filesystems

GIT_REPOSITORIES=	lizardfs
GIT_REPO.lizardfs=	https://github.com/lizardfs/lizardfs.git
GIT_TAG.lizardfs=	v${PKGVERSION_NOREV}

MAINTANER=	cfkoch@edgebsd.org
HOMEPAGE=	http://lizardfs.com/
COMMENT=	Open source, distributed file system
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/lizardfs
USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		..

pre-configure:
.for dir in ${CONFIGURE_DIRS}
	mkdir -p ${WRKSRC}/${dir}
.endfor

.include "../../mk/fuse.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
