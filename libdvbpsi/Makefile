# $NetBSD: Makefile,v 1.1.1.1 2003/11/12 05:49:54 blef Exp $
#

DISTNAME=		libdvbpsi-0.1.3
CATEGORIES=		wip
MASTER_SITES=		http://www.videolan.org/pub/libdvbpsi/0.1.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://developers.videolan.org/libdvbpsi/
COMMENT=		MPEG TS and DVB PSI table encoding and decoding library

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
