# $NetBSD: Makefile,v 1.1.1.1 2003/09/06 17:28:19 marc Exp $

DISTNAME=	koffice-i18n-de-1.2.1
WRKSRC=         ${WRKDIR}/koffice-i18n-de
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.2.1/src/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=     recht@NetBSD.org
HOMEPAGE=       http://www.koffice.org/
COMMENT=	Language pack for KOffice

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=              YES

.include "../../misc/koffice/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
