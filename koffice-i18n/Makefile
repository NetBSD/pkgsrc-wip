# $NetBSD: Makefile,v 1.1.1.1 2004/08/23 07:28:43 ianzag Exp $

DISTNAME=		koffice-i18n-1.3.2
CATEGORIES=		x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.2/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.koffice.org/
COMMENT=		KOffice full language pack

#WRKSRC=			${WRKDIR}/kde-i18n-1.3.2

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
