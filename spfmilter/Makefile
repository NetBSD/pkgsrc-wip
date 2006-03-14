# $NetBSD: Makefile,v 1.4 2006/03/14 01:28:15 jlamwww Exp $

DISTNAME=	spfmilter-1.0.8
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/patch/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework (SPF) as a milter

GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
RCD_SCRIPTS=	spfmilter

BUILDLINK_DEPENDS.libmilter?=	libmilter>=8.13.0

.include "../../mail/libmilter/buildlink3.mk"
.include "../../wip/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
