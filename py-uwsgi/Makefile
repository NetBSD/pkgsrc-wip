# $NetBSD: Makefile,v 1.2 2014/01/05 03:37:54 othyro Exp $

DISTNAME=	uwsgi-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

SUBST_CLASSES+=		options
SUBST_FILES.options=	buildconf/base.ini
SUBST_MESSAGE.options=	Fixing PKG_OPTIONS.
SUBST_STAGE.options=	pre-configure

.include "options.mk"

INSTALL_ENV+=		UWSGI_INCLUDES=${PREFIX}/include
INSTALLATION_DIRS+=	share/examples/py-uwsgi

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/uwsgi ${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/py-uwsgi

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
