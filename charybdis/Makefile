# $NetBSD$

DISTNAME=	charybdis-4.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=charybdis-ircd/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freenode/ircd-seven/
COMMENT=	Freenode's IRC server daemon
LICENSE=	gnu-gpl-v2

USE_TOOLS=	automake autoconf autoreconf

HAS_CONFIGURE=	yes

.include "../../mk/compiler.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--enable-kqueue
.endif

INSTALLATION_DIRS+=	bin

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
