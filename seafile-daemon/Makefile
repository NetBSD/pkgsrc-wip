# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile
VERSION=	6.0.0
PKGNAME=	${GITHUB_PROJECT}-daemon-${VERSION}
GITHUB_TAG=	v${VERSION}-server
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile daemon
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${GITHUB_PROJECT}-daemon
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

AUTOMAKE_REQD=	1.9

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake aclocal autoheader autoconf gmake

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 27


CONFIGURE_ARGS+=	--disable-fuse \
			--disable-server

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	libsearpc-3.0{,nb*}:../../wip/seafile-libsearpc

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	app/seaf-cli

SUBST_SED.python=	-e 's,/usr/bin/env python,${PYTHONBIN},'

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
