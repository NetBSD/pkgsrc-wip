# $NetBSD$

DISTNAME=	objfw-0.91
CATEGORIES=	devel

COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3
HOMEPAGE=	https://heap.zone/objfw/
MAINTAINER=	js@heap.zone

GIT_REPOSITORIES=	objfw
GIT_REPO.objfw=		https://github.com/ObjFW/ObjFW.git

WRKSRC=			${WRKDIR}/objfw
USE_TOOLS=		aclocal automake
GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	OBJCFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

PLIST_VARS+=	runtime bridge

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.runtime =	yes
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
