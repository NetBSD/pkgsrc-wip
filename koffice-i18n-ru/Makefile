# $NetBSD: Makefile,v 1.1.1.1 2004/06/26 10:02:51 ianzag Exp $

DISTNAME=		koffice-i18n-ru-1.3.1
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		x11
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.1/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.koffice.org/
COMMENT=		KOffice ru language pack

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
