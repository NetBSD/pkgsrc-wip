# $NetBSD: Makefile,v 1.1 2005/02/28 05:36:12 ianzag Exp $

DISTNAME=	koffice-i18n-nb-1.3.5
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.5/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.koffice.org/
COMMENT=	Norwegian Bokmal language pack for KOffice

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../misc/koffice/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
