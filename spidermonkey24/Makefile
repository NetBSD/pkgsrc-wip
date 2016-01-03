# $NetBSD: Makefile,v 1.1 2014/02/06 15:12:17 fhajny Exp $

DISTNAME=	mozjs-24.2.0
PKGNAME=	${DISTNAME:S/mozjs/spidermonkey24/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=js/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/js/src

USE_TOOLS+=		pkg-config perl:build gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--enable-threadsafe
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

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
