# $NetBSD: Makefile,v 1.1.1.1 2009/05/05 21:33:40 jihbed Exp $
#

DISTNAME=	csp2B1.2
PKGNAME=	csp2b-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ecs.soton.ac.uk/~mjb/csp2B/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://users.ecs.soton.ac.uk/mjb/csp2B/
COMMENT=	The csp2B Tool written in Moscow ML
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	moscow_ml>=2.01:../../lang/moscow_ml

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}
EDGDIR=		${PREFIX}/share/examples/${PKGNAME}


do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.ps ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${EDGDIR}

.include "../../mk/bsd.pkg.mk"
