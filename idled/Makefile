# $NetBSD: Makefile,v 1.3 2004/04/25 18:30:33 blef Exp $
#

DISTNAME=	idled-1.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/

MAINTAINER=	tmarc@NetBSD.org.pl
HOMEPAGE=	http://www.darkwing.com/idled/
COMMENT=	Daemon that logs out idle users

USE_BUILDLINK3=	YES

post-extract:
	${RM} -f ${WRKSRC}/parse.c ${WRKSRC}/scan.c

.include "../../mk/bsd.pkg.mk"
