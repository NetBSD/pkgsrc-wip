# $NetBSD: Makefile,v 1.14 2013/01/20 01:10:40 othyro Exp $
#

DISTNAME=	avida-2.12.4-src
PKGNAME=	${DISTNAME:S/-src//1}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=avida/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://avida.devosoft.org/
COMMENT=	Avida is an auto-adaptive genetic system
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DAVD_CMDLINE=ON

.include "options.mk"

pre-configure:
	${MKDIR} ${WRKSRC}/build;
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ARGS} ${CMAKE} ..

.include "../../mk/bsd.pkg.mk"
