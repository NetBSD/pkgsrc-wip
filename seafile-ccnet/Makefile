# $NetBSD$
VERSION=	6.0.0
PKGNAME=	ccnet-${VERSION}
CATEGORIES=	net
GITHUB_TAG=	v${VERSION}-server
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Framework for writing networked applications in C
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	seafile-ccnet
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake aclocal autoheader automake autoconf

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	30 31 32 33 34 35 36 37

DEPENDS+=		libsearpc-3.0{,nb*}:../../wip/seafile-libsearpc

CONFIGURE_ARGS+=	--enable-server \
			--disable-compile-demo

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/libzdb/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/seafile-libsearpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
