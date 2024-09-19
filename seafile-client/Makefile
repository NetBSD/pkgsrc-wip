# $NetBSD$

CATEGORIES=	net
GITHUB_PROJECT=	seafile
VERSION=	6.0.4
DISTNAME=	v${VERSION}
PKGNAME=	seafile-client-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haiwen/}
GITHUB_TAG=	v${VERSION}

DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://seafile.com/
COMMENT=	Seafile client
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
AUTOMAKE_REQD=	1.9

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake aclocal autoheader autoconf gmake

CONFLICTS=	seafile-server-[0-9]*

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing Python path
SUBST_FILES.python=	app/seaf-cli daemon/seaf-daemon
SUBST_SED.python=	-e "s,/usr/bin/env python,${PYTHONBIN},"

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../lang/python/egg.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/ccnet-server/buildlink3.mk"
.include "../../wip/libsearpc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../wip/libevhtp/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
