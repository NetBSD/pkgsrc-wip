# $NetBSD: Makefile,v 1.1.1.1 2003/10/17 08:15:18 minskim Exp $
#

DISTNAME=	libgpg-error-0.5
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnupg.org/GnuPG/alpha/libgpg-error/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
