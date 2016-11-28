# $NetBSD$
VERSION=	3.0
PKGNAME=	libsearpc-${VERSION}
CATEGORIES=	net
GITHUB_TAG=	v${VERSION}-latest
DISTNAME=	${GITHUB_TAG}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Simple RPC framework based on GObject system
LICENSE=	apache-2.0

DIST_SUBDIR=	seafile-libsearpc
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-latest

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake automake autoconf aclocal autoheader

DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson


PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	30 31 32 33 34 35 36 37

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	lib/searpc-codegen.py

SUBST_SED.python=	-e 's,/usr/bin/env python2,${PYTHONBIN},'

pre-configure:
	set -e; cd ${WRKSRC}; libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf


.include "../../textproc/jansson/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
