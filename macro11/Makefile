# $NetBSD$

DISTNAME=	macro11-0.7.2
CATEGORIES=	cross
MASTER_SITES=	https://gitlab.com/Rhialto/macro11/-/archive/${TAG}/
DISTFILES+=	macro11-${TAG}.tar.gz
TAG=		macro11-v${PKGVERSION_NOREV}
TARDIR=		macro11-${TAG}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://gitlab.com/Rhialto/macro11/
COMMENT=	PDP-11 crossassembler
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
REPLACE_PERL+=	obj2bin/obj2bin.pl
WRKSRC=		${WRKDIR}/${TARDIR}

FORTIFY_SUPPORTED=	no	# fortify re#defines gets to something weird
INSTALLATION_DIRS=	${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macro11 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dumpobj ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/obj2bin/obj2bin.pl ${DESTDIR}${PREFIX}/bin/

do-test:
	cd ${WRKSRC} && ${MAKE_PROGRAM} tests

.include "../../mk/bsd.pkg.mk"
