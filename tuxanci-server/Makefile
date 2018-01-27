# $NetBSD: Makefile,v 1.3 2012/11/13 22:25:50 othyro Exp $
#

DISTNAME=	tuxanci-0.20.0-src
PKGNAME=	tuxanci-server-0.20.0
CATEGORIES=	games
MASTER_SITES=	http://download.tuxanci.org/0.20.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://download.tuxanci.org/0.20.0/
COMMENT=	Server of Czechoslovak multiplatform action game like Bulanci


WRKSRC=	${WRKDIR}/pkgs/tuxanci-0.20.0-src

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

EGDIR=		${PREFIX}/share/examples
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_DIRS+=	${PKG_SYSCONFDIR}/tuxanci-server
CONF_FILES+=	${EGDIR}/tuxanci-server/server.conf ${PKG_SYSCONFDIR}/tuxanci-server/server.conf

CMAKE_ARGS+=	-DServer=1 \
		-DPREFIX=\\\"${PREFIX}/\\\" \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DEGDIR=${EGDIR}

.include "../../mk/bsd.pkg.mk"
