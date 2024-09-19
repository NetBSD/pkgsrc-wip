# $NetBSD: Makefile,v 1.8 2012/10/07 16:23:16 asau Exp $

DISTNAME=	spfmilter-1.0.8
CATEGORIES=	mail
MASTER_SITES=	https://www.libspf2.org/patch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework (SPF) as a milter


GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
RCD_SCRIPTS=	spfmilter

BUILDLINK_API_DEPENDS.libmilter?=	libmilter>=8.13.0

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
