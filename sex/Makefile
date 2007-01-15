# $NetBSD: Makefile,v 1.1.1.1 2007/01/15 17:04:34 netcap Exp $

DISTNAME=	sex-1.0
CATEGORIES=	games
MASTER_SITES=	http://spatula.net/software/sex/

MAINTAINER=	jfranz@thundrix.ch
COMMENT=	Spout silly, random porn-like text

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/Makefile.dist > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
