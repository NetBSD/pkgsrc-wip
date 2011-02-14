# $NetBSD: Makefile,v 1.3 2011/02/14 06:03:50 jafour1 Exp $
DISTNAME=	mongodb-src-r1.6.5
CATEGORIES=	database
MASTER_SITES=	http://downloads.mongodb.org/src

MAINTAINER=	ober@netbsd.org
HOMEPAGE=	http://mongodb.org/
COMMENT=	A NOSQL distributed document-oriented database
EXTRACT_SUFX=	.tar.gz


PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes
#USE_TOOLS+= 	perl
USE_LANGUAGES+=	c c++
DESTDIR=${LOCALBASE}

DEPENDS+=       boost-build:../../devel/boost-build
DEPENDS+=       boost-docs:../../devel/boost-docs
DEPENDS+=       boost-headers:../../devel/boost-headers
DEPENDS+=       boost-jam:../../devel/boost-jam
DEPENDS+=       boost-libs:../../devel/boost-libs
DEPENDS+=       boost-python:../../devel/boost-python
DEPENDS+=       pcre:../../devel/pcre
DEPENDS+=       libexecinfo:../../wip/libexecinfo
DEPENDS+=       spidermonkey:../../lang/spidermonkey

SCONS_BIN=			${PREFIX}/bin/scons
SCONS_ARGS= "--prefix=/usr/pkg"
SCONS_INSTALL_TARGET= "install"
SCONS_TARGET=	all
SCONS_ARGS= 	--prefix=${PREFIX}
SCONS_ARGS+=	--full
SCONS_ARGS+= 	--libpath=${LIBPATH}

do-build:
	cd ${WRKSRC} && ${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} ${SCONS_TARGET}

do-install:
	cd ${WRKSRC} && ${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} ${SCONS_TARGET} ${SCONS_INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"

