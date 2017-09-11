# $NetBSD$
# vim: noexpandtab:

DISTNAME=	wjelement-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=netmail-open/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tr@vispaul.me
HOMEPAGE=	https://github.com/netmail-open/wjelement/
COMMENT=	Flexible JSON manipulation and schema validataion in C
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes

CHECK_PORTABILITY_SKIP=	src/cli/wje
REPLACE_SH=	src/cli/wje

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SRC+=		PLIST.dylib
.endif

.include	"../../mk/bsd.pkg.mk"
