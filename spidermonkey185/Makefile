# $NetBSD: Makefile,v 1.4 2012/11/03 15:07:33 thomasklausner Exp $
#

DISTNAME=	js185-1.0.0
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-1.1

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

WRKSRC=		${WRKDIR}/js-1.8.5/js/src
USE_TOOLS+=	pkg-config perl:build gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=	NO

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--enable-threadsafe

#XXX workaround for js-config command and mozjs185.pc
CONFIGURE_ENV+=		MOZILLA_VERSION=4.0

PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	mozjs185.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	ARCH=X64
.else
PLIST_SUBST+=	ARCH=${MACHINE_ARCH}
.endif

.include "../../lang/python/application.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
