# $NetBSD: Makefile,v 1.1.1.1 2004/09/01 16:02:12 adrian_p Exp $

DISTNAME=	spfmilter-1.0.8
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/patch/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/spfmilter/
COMMENT=	Implementation of the Sender Policy Framework (SPF) as a milter

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
USE_PKGINSTALL=	YES
RCD_SCRIPTS=	spfmilter

BUILDLINK_DEPENDS.libmilter?=	libmilter>=8.13.0

.include "../../mail/libmilter/buildlink3.mk"
.include "../../wip/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
