# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile-server
VERSION=	6.0.9
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
GITHUB_TAG=	v${VERSION}-server
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile server
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${GITHUB_PROJECT}-${VERSION}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

AUTOMAKE_REQD=	1.9

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake aclocal autoheader autoconf gmake

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 27

CPPFLAGS+=	-I${PREFIX}/include -I${PREFIX}/include/evhtp
LDFLAGS+=	-L${PREFIX}/lib

CONFIGURE_ARGS+=	--disable-fuse \
			--disable-server

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

CONFLICTS=	seafile-client-[0-9]*

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	tools/seafile-admin

SUBST_SED.python=	-e 's,/usr/bin/env python,${PYTHONBIN},'

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/libevhtp/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../wip/libsearpc/buildlink3.mk"
.include "../../wip/ccnet-server/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
