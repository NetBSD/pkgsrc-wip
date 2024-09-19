# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:35 asau Exp $
#

DISTNAME=	LambertW-1.1
PKGNAME=	lamvbertw-1.1
CATEGORIES=	math
MASTER_SITES=	http://sabotin.ung.si/~darko/LambertW/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sabotin.ung.si/~darko/LambertW/
COMMENT=	Lambert W Function for Applications in Physics
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lambert-w	${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
