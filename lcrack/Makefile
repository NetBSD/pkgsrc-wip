# $NetBSD: Makefile,v 1.2 2004/11/27 23:44:02 poppnk Exp $
#

DISTNAME=		lcrack-20040914
CATEGORIES=		wip security
MASTER_SITES=		http://usuarios.lycos.es/reinob/lcrack/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://usuarios.lycos.es/reinob/
COMMENT=		Generic password hash cracker

WRKSRC=		${WRKDIR}/
HAS_CONFIGURE=	yes
USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=unknown  # talking with authors to solve this :)

do-install:
.for _file_ in lcrack mkword regex mktbl
	${INSTALL_PROGRAM} ${WRKSRC}/${_file_} ${PREFIX}/bin/${_file_}
.endfor
.undef _file_

.include "../../mk/bsd.pkg.mk"
