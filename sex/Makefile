# $NetBSD: Makefile,v 1.3 2007/08/01 00:52:26 netcap Exp $

DISTNAME=	sex-1.0
CATEGORIES=	games
MASTER_SITES=	http://spatula.net/software/sex/

MAINTAINER=	jfranz@bsdprojects.net
COMMENT=	Yet another program for spouting silly random phrases

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/Makefile.dist > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
