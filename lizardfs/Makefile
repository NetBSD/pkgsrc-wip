# $NetBSD$

PKGNAME=	lizardfs-${VERSION}
VERSION=	3.10.4
CATEGORIES=	filesystems
MASTER_SITES=	# defined

GIT_REPOSITORIES=	lizardfs
GIT_REPO.lizardfs=	https://github.com/christiank/lizardfs.git
GIT_BRANCH.lizardfs=	cfkoch_netbsdrefuse

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

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
