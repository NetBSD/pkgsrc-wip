# $NetBSD: Makefile,v 1.7 2013/05/01 20:25:28 kristerw Exp $

DISTNAME=		v8
CATEGORIES=		lang
MASTER_SITES=		# none?

MAINTAINER=		msporleder@gmail.com
COMMENT=		V8 JavaScript Engine
HOMEPAGE=		http://code.google.com/p/v8
LICENSE=		modified-bsd

SVN_REPOSITORIES=	v8
SVN_ROOT.v8=		http://v8.googlecode.com/svn/trunk/
SVN_MODULE.v8=		v8

DEPENDS+=		libexecinfo>=1:../../devel/libexecinfo
BUILD_DEPENDS+=		scons>=1:../../devel/scons

NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true library=shared PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC}

.include "../../lang/python/pyversion.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
