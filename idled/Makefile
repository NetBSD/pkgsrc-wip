# $NetBSD: Makefile,v 1.2 2003/08/29 11:49:28 thomasklausner Exp $
#

DISTNAME=	idled-1.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/

MAINTAINER=	tmarc@NetBSD.org.pl
HOMEPAGE=	http://www.darkwing.com/idled/
COMMENT=	Daemon that logs out idle users

USE_BUILDLINK2=	YES

post-extract:
	${RM} -f ${WRKSRC}/parse.c ${WRKSRC}/scan.c

.include "../../mk/bsd.pkg.mk"
