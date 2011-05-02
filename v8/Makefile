DISTNAME=		v8
CATEGORIES=		wip
PKGREVISION=		1

MAINTAINER=		msporleder@gmail.com
COMMENT=		V8 JavaScript Engine
HOMEPAGE=		http://code.google.com/p/v8
LICENSE=		modified-bsd
PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE=		yes

SVN_REPOSITORIES=	v8
SVN_ROOT.v8=		http://v8.googlecode.com/svn/trunk/
SVN_MODULE.v8=		v8

DEPENDS+=		libexecinfo>=1:../../wip/libexecinfo
BUILD_DEPENDS+=		scons>=1:../../devel/scons

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons debug=true relase=true library=shared PREFIX=${PREFIX}

.include "../../wip/mk/svn-package.mk"
.include "../../lang/python26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
