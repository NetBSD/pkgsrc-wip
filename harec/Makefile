# $NetBSD$

PKGNAME=	harec-0.24.0
DISTNAME=	${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/harec/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	Hare language bootstrap compiler
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

TOOL_DEPENDS+=		qbe>=1.2:../../lang/qbe

do-configure:
	${RUN} cp ${FILESDIR}/config.mk ${WRKSRC}/config.mk

.include "../../mk/bsd.pkg.mk"
