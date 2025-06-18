# $NetBSD$

DISTNAME=	ltl2ba-1.3
CATEGORIES=	math
MASTER_SITES=	http://www.lsv.fr/~gastin/ltl2ba/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lsv.fr/~gastin/ltl2ba/
COMMENT=	Fast translation from LTL formulae to Buchi automata
LICENSE=	gnu-gpl-v2

LTL2BA=	ltl2ba

BUILD_TARGET=		${LTL2BA}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${LTL2BA} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
