# $NetBSD: Makefile,v 1.3 2004/04/26 02:22:25 blef Exp $

DISTNAME=	koffice-i18n-es-1.2.1
WRKSRC=         ${WRKDIR}/koffice-i18n-es
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.2.1/src/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://www.koffice.org/
COMMENT=	Language bindings for the Koffice

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
