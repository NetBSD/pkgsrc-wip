# $NetBSD: Makefile,v 1.1.1.1 2004/09/22 15:13:52 ianzag Exp $

DISTNAME=		koffice-i18n-se-1.3.3
CATEGORIES=		x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.3/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.koffice.org/
COMMENT=		KOffice se language pack

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
