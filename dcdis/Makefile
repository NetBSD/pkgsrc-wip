# $NetBSD$

DISTNAME=	dcdis-0.4a
CATEGORIES=	devel
MASTER_SITES=	https://www.ludd.ltu.se/~jlo/dc/

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://www.ludd.ltu.se/~jlo/dc/
COMMENT=	Simple Dreamcast disassembler
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dcdis ${DESTDIR}${PREFIX}/bin/dcdis

.include "../../mk/bsd.pkg.mk"
