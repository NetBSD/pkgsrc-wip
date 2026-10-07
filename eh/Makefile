# $NetBSD$
DISTNAME=		eh-1.9.0
CATEGORIES=		editors
MASTER_SITES=		https://codeberg.org/SirWumpus/eh/archive/
DISTFILES=		v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=		ricardsonwilliams@gmail.com
HOMEPAGE=		https://codeberg.org/SirWumpus/eh/
COMMENT=		Small terminal text editor
LICENSE=		eh-license

WRKSRC=			${WRKDIR}/eh

MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eh ${DESTDIR}${PREFIX}/bin/eh

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
