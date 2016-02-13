# $NetBSD: Makefile,v 1.3 2015/04/10 11:43:49 krytarowski Exp $
#

DISTNAME=	mozjs17.0.0
PKGNAME=	${DISTNAME:S/mozjs17/spidermonkey17-17/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl gmake

CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--enable-threadsafe
CONFIGURE_ARGS+=	--enable-system-ffi

CONFIGURE_DIRS=		js/src

PKGCONFIG_OVERRIDE+=	js/src/ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	js/src/js.pc.in

TEST_TARGET=		check

# Adjust file permissions
post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/js-17.0/*.*
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/js-17.0/*/*.*
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libmozjs-17.0.a
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-17.0.pc

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
