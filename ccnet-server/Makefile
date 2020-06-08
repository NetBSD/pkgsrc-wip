# $NetBSD$

PKGNAME=	ccnet-server-7.1.4
CATEGORIES=	devel net

MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}-server
DISTNAME=	${GITHUB_TAG}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Framework for writing networked applications in C
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	seafile-ccnet
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.0

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config autoconf automake

PY_PATCHPLIST=	yes

CONFIGURE_ARGS+=	--enable-server \
			--disable-compile-demo

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/libzdb/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/libsearpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
