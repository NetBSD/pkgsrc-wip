# $NetBSD: Makefile,v 1.2 2003/12/05 04:04:04 minskim Exp $
#

DISTNAME=	libgpg-error-0.6
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnupg.org/GnuPG/alpha/libgpg-error/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
