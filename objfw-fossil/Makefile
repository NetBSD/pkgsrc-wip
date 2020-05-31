# $NetBSD$

DISTNAME=	objfw-1.1
CATEGORIES=	devel

COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3
HOMEPAGE=	https://objfw.nil.im/
MAINTAINER=	js@pkgsrc.org

FOSSIL_REPO=		https://objfw.nil.im

WRKSRC=			${WRKDIR}/objfw
USE_TOOLS=		aclocal automake
GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

PLIST_VARS+=	runtime bridge

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.runtime=	yes
.endif
.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD"
PLIST.ipx=	yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../wip/mk/fossil-package.mk"
.include "../../mk/bsd.pkg.mk"
