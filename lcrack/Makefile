# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:19 thomasklausner Exp $
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

do-install:
.for _file_ in lcrack mkword regex mktbl
	${INSTALL_PROGRAM} ${WRKSRC}/${_file_} ${PREFIX}/bin/${_file_}
.endfor
.undef _file_

.include "../../mk/bsd.pkg.mk"
