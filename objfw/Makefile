# $NetBSD$

DISTNAME=	objfw-0.90
MASTER_SITES=	https://heap.zone/objfw/downloads/
CATEGORIES=	devel
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3
HOMEPAGE=	https://heap.zone/objfw/
MAINTAINER=	js@heap.zone

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.runtime
.else
PLIST_SRC+=	${PKGDIR}/PLIST.bridge
.endif

.include "../../mk/bsd.pkg.mk"
