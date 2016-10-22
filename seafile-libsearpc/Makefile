# $NetBSD$
PKGNAME=	seafile-libsearpc-3.0
CATEGORIES=	net
GHCOMMIT=	258d508e6cbc7e80e3e3f51a66390c162049deff
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/libsearpc/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Simple RPC framework based on GObject system
LICENSE=	apache-2.0

DIST_SUBDIR=	seafile
WRKSRC=		${WRKDIR}/libsearpc-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

AUTOCONF_VERSION=2.61
AUTOMAKE_VERSION=1.9

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake automake autoreconf

#DEPENDS+=	${PYPKGPREFIX}-simplejson>=../../converters/py-simplejson


pre-configure:
	cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} && AUTOMAKE_VERSION=${AUTOMAKE_VERSION} autoreconf -fi


.include "../../textproc/jansson/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
