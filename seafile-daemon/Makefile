# $NetBSD$
PKGNAME=	seafile-daemon-6.0.0
CATEGORIES=	net
GHCOMMIT=	bea8cc526ed37b8c9599e5f526d934c8ec90d288
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/seafile/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile daemon
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	seafile
WRKSRC=		${WRKDIR}/seafile-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

AUTOMAKE_REQD=	1.9

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake aclocal autoheader autoconf gmake

PY_PATCHPLIST=	yes

CONFIGURE_ARGS+=	--disable-fuse \
			--disable-server

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	seafile-libsearpc-3.0{,nb*}:../../wip/seafile-libsearpc

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/libinotify/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../wip/seafile-libsearpc/buildlink3.mk"
.include "../../wip/seafile-ccnet/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
