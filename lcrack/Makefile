# $NetBSD: Makefile,v 1.5 2012/10/01 22:17:50 asau Exp $
#

DISTNAME=		lcrack-20040914
CATEGORIES=		security
MASTER_SITES=		http://usuarios.lycos.es/reinob/lcrack/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://usuarios.lycos.es/reinob/
COMMENT=		Generic password hash cracker

WRKSRC=		${WRKDIR}/
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=unknown  # talking with authors to solve this :)

INSTALLATION_DIRS=	bin

do-install:
.for _file_ in lcrack mkword regex mktbl
	${INSTALL_PROGRAM} ${WRKSRC}/${_file_} ${DESTDIR}${PREFIX}/bin/${_file_}
.endfor
.undef _file_

.include "../../mk/bsd.pkg.mk"
