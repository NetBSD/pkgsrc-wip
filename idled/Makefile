# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:10 tvierling Exp $
#

DISTNAME=	idled-1.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/

MAINTAINER=	tmarc@NetBSD.org.pl
HOMEPAGE=	http://www.darkwing.com/idled/
COMMENT=	Daemon that logs out idle users


post-extract:
	${RM} -f ${WRKSRC}/parse.c ${WRKSRC}/scan.c

.include "../../mk/bsd.pkg.mk"
