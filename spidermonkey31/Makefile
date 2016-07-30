# $NetBSD: Makefile,v 1.1 2014/02/06 15:12:24 fhajny Exp $

DISTNAME=	mozjs-31.2.0.rc0
PKGNAME=	${DISTNAME:S/mozjs/spidermonkey31/}
CATEGORIES=	lang
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=js/}
MASTER_SITES=	https://people.mozilla.org/~sstangl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:R}/js/src

USE_TOOLS+=		pkg-config perl:build gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--enable-threadsafe
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-nspr

PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	js.pc.in

CHECK_PORTABILITY_SKIP+=	tests/update-test262.sh

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=			PYTHON=${PYTHONBIN:Q}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	ARCH=X64
.else
PLIST_SUBST+=	ARCH=${MACHINE_ARCH}
.endif

post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/lib/libmozjs-24.dylib \
		${DESTDIR}${PREFIX}/lib/libmozjs-24.dylib
.endif
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-24/*.*
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-24/*/*.*
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libmozjs-24.a
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-24.pc

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
