# $NetBSD$

DISTNAME=	src-0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/src/

MAINTAINER=	esg@sdf.org
HOMEPAGE=	http://www.catb.org/~esr/src/
COMMENT=	Simple Revision Control
LICENSE=	modified-bsd

REPLACE_PYTHON=	src
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
