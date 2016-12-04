# $NetBSD$

CATEGORIES=	filesystems
VERSION=	0.2.1
GITHUB_PROJECT=	simple-mtpfs
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
DISTNAME=	simple-mtpfs-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=phatina/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://github.com/phatina/simple-mtpfs
COMMENT=	FUSE module for interacting with MTP devices
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	simple-mtpfs
WRKSRC=		${WRKDIR}/simple-mtpfs-${PKGNAME_NOREV}

CHECK_PORTABILITY_SKIP+=	configure.ac

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
