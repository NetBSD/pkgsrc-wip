# $NetBSD: Makefile,v 1.3 2004/04/26 02:20:35 blef Exp $

DISTNAME=	koffice-i18n-de-1.2.1
WRKSRC=         ${WRKDIR}/koffice-i18n-de
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.2.1/src/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=     recht@NetBSD.org
HOMEPAGE=       http://www.koffice.org/
COMMENT=	Language pack for KOffice

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
