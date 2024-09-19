# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:56 asau Exp $
#

DISTNAME=	csp2B1.2
PKGNAME=	csp2b-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ecs.soton.ac.uk/~mjb/csp2B/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://users.ecs.soton.ac.uk/mjb/csp2B/
COMMENT=	The csp2B Tool written in Moscow ML
#LICENSE=	LICENSE

WRKSRC=	${WRKDIR}/${DISTNAME}

DEPENDS+=	moscow_ml>=2.01:../../lang/moscow_ml

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}
EDGDIR=		${PREFIX}/share/examples/${PKGNAME}

MOSMLC=		${PREFIX}/bin/mosmlc


INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && \
		${MOSMLC} csp2B.sig \
		${MOSMLC} -o csp2B csp2B.sml

do-install:
	${INSTALL_DATA} ${WRKSRC}/csp2B	${DESTDIR}${PREFIX}/bin
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/csp2B
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.ps ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${EDGDIR}

.include "../../mk/bsd.pkg.mk"
