# $NetBSD: Makefile,v 1.1.1.1 2007/03/10 23:14:00 uhabel Exp $
#

DISTNAME=	gpsbabel-1.3.3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsbabel/}

MAINTAINER=	uli@habel.name
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
