# $NetBSD$

DISTNAME=	unimrcp-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=unispeech/}
GITHUB_TAG=	unimrcp-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/unispeech/unimrcp/
COMMENT=	Open-source cross-platform implementation of MRCP[v1-2]
LICENSE=	apache-2.0

HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal autoconf automake patch

CONFIGURE_ARGS+=	--prefix=${PREFIX}/unimrcp
CONFIGURE_ARGS+=	--with-apr=${PREFIX}/unimrcp/apr
CONFIGURE_ARGS+=	--with-apr-util=${PREFIX}/unimrcp/apr
CONFIGURE_ARGS+=	--with-sofia-sip=${PREFIX}/unimrcp/sofia-sip

INSTALLATION_DIRS+=	unimrcp/include
INSTALLATION_DIRS+=	unimrcp/lib

pre-configure:
	set -x; cd ${WRKSRC}; autoreconf -fiv; aclocal -I build/acmacros; ${RM} -rf autom4te.cache
	${PATCH} ${WRKSRC}/configure ${BUILD_DIR}/files/patch-configure

.include "../../wip/unimrcp-sofiasip/buildlink3.mk"
.include "../../wip/unimrcp-apr/buildlink3.mk"
.include "../../wip/unimrcp-aprutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../mk/bsd.prefs.mk"
