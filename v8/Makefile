# $NetBSD: Makefile,v 1.3 2011/09/10 19:57:09 genolopolis Exp $

DISTNAME=		v8
CATEGORIES=		wip
MASTER_SITES=		# none?

MAINTAINER=		msporleder@gmail.com
COMMENT=		V8 JavaScript Engine
HOMEPAGE=		http://code.google.com/p/v8
LICENSE=		modified-bsd

SVN_REPOSITORIES=	v8
SVN_ROOT.v8=		http://v8.googlecode.com/svn/trunk/
SVN_MODULE.v8=		v8

DEPENDS+=		libexecinfo>=1:../../wip/libexecinfo
BUILD_DEPENDS+=		scons>=1:../../devel/scons

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true library=shared PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC}

.include "../../lang/python26/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
