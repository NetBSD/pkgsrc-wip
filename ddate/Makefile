# $NetBSD: Makefile,v 1.2 2007/01/07 09:16:00 rillig Exp $

DISTNAME=	ddate
PKGNAME=	ddate-19950925
CATEGORIES=	games
MASTER_SITES=	http://ftp.cc.com.au/pub/users/cafuego/emperor_norton/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://yoyo.its.monash.edu.au/~acb/norton/
COMMENT=	The enhanced Discordian date program

DOCDIR=		${PREFIX}/share/doc/ddate

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddate ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/ddate.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
