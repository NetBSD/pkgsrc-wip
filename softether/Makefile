# $NetBSD$

NAME=		softether
VERSION=	4.29-9680
PKGNAME=	${NAME}-${VERSION}
GITHUB_PROJECT=	SoftEtherVPN_Stable
DISTNAME=	softether-src-${GITHUB_RELEASE}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=SoftEtherVPN/}
GITHUB_RELEASE=	v4.29-9680-rtm
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	william@welliver.org
HOMEPAGE=	https://github.com/SoftEtherVPN/SoftEtherVPN_Stable/
COMMENT=	Powerful and easy-to-use multi-protocol VPN software
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/v${VERSION}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake

BUILD_TARGET=	build

BUILD_MAKE_FLAGS+=	LDFLAGS="-L${PREFIX}/lib"
BUILD_MAKE_FLAGS+=	CFLAGS="-I${PREFIX}/include"
BUILD_MAKE_FLAGS+=	PREFIX="${PREFIX}"

INSTALL_MAKE_FLAGS+=	PREFIX="${PREFIX}"
INSTALL_MAKE_FLAGS+=	_INSTALL_PREFIX="${DESTDIR}"
INSTALLATION_DIRS+=	bin share/doc/${NAME}

DOC_FILES=	README.TXT LICENSE.TXT AUTHORS.TXT WARNING.TXT

post-install:
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
	${DESTDIR}${PREFIX}/share/doc/${NAME}/${x}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
