# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 10:50:53 cjep Exp $
#

DISTNAME=	idled-1.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.darkwing.com/idled/download/

MAINTAINER=	tmarc@netbsd.org.pl
HOMEPAGE=	http://www.darkwing.com/idled/
COMMENT=	Daemon that logs out idle users

USE_BUILDLINK2=	YES

post-extract:
	${RM} -f ${WRKSRC}/parse.c ${WRKSRC}/scan.c

.include "../../mk/bsd.pkg.mk"
