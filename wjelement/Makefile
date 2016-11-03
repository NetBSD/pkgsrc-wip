# $NetBSD$
# vim: noexpandtab:

DISTNAME=	wjelement-v1.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=netmail-open/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	Tr@visPaul.me
HOMEPAGE=	https://github.com/netmail-open/wjelement/
COMMENT=	Flexible JSON manipulation and schema validataion in C
LICENSE=	gnu-lgpl-v2

GITHUB_PROJECT=	wjelement
GITHUB_TAG=	v1.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=netmail-open/}

WRKSRC=		${WRKDIR}/wjelement-1.1
USE_CMAKE=	yes

CHECK_PORTABILITY_SKIP=	src/cli/wje
REPLACE_SH=	src/cli/wje

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	DYLIB=.dylib
PLIST_SUBST+=	SO=
.else
PLIST_SUBST+=	SO=.so
PLIST_SUBST+=	DYLIB=
.endif

.include	"../../mk/bsd.pkg.mk"
