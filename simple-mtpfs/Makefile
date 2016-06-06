# $NetBSD$
PKGNAME=	simple-mtpfs-0.2-24
CATEGORIES=	filesystems
GHCOMMIT=	ea08fdb1299a2f53ac758f15c0377434ac0bbf89
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=simple-mtpfs/}
EXTRACT_SUFX=	.zip
#GIT_COMMIT=	EA08FDB

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://github.com/phatina/simple-mtpfs
COMMENT=	FUSE module for interacting with MTP devices
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	simple-mtpfs
WRKSRC=		${WRKDIR}/simple-mtpfs-${GHCOMMIT}

GNU_CONFIGURE=	yes

AUTOMAKE_REQD=	1.7.1
USE_LANGUAGES+=	c c++
MAKE_FILE=	makefile
USE_TOOLS+=	pkg-config automake aclocal autoconf

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/libmtp/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
