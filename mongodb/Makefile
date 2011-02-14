# $NetBSD: Makefile,v 1.1 2011/02/14 03:36:13 jafour1 Exp $
DISTNAME=	mongodb-src-r1.6.5
CATEGORIES=	database
MASTER_SITES=	http://downloads.mongodb.org/src

MAINTAINER=	ober@netbsd.org
HOMEPAGE=	http://mongodb.org/
COMMENT=	MongoDB is a powerful,flexible, and scalable data store.
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

SCONS=			${PREFIX}/bin/scons
SCONS_ARGS= ". --prefix=/usr/pkg"
SCONS_INSTALL= "install"

do-build:
	cd ${WRKSRC} && ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SCONS} ${SCONS_ARGS} #{SCONS_INSTALL}

.include "../../mk/bsd.pkg.mk"

