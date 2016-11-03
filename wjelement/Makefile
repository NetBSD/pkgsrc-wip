# $NetBSD$
# vim: noexpandtab:

DISTNAME=	wjelement-v1.1
PKGREVISION=	1
GITHUB_PROJECT=	wjelement
GITHUB_TAG=	v1.1
DIST_SUBDIR=	${GITHUB_PROJECT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=netmail-open/}
CATEGORIES=	devel

MAINTAINER=	Tr@visPaul.me
HOMEPAGE=	https://github.com/netmail-open/wjelement/
COMMENT=	Flexible JSON manipulation and schema validataion in C
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/wjelement-1.1
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	EXT=dylib
.else
PLIST_SUBST+=	EXT=so
.endif

.include	"../../mk/bsd.pkg.mk"
