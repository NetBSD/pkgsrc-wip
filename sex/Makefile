# $NetBSD: Makefile,v 1.2 2007/01/15 17:08:45 netcap Exp $

DISTNAME=	sex-1.0
CATEGORIES=	games
MASTER_SITES=	http://spatula.net/software/sex/

MAINTAINER=	jfranz@bsdprojects.net
COMMENT=	Yet another program for spouting silly random phrases.

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/Makefile.dist > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
