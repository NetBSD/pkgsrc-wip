# $NetBSD: Makefile,v 1.2 2003/05/14 01:10:12 lsed Exp $
#

DISTNAME=	libtasn1-0.2.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
