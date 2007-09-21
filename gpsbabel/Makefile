# $NetBSD: Makefile,v 1.2 2007/09/21 05:04:52 marttikuparinen Exp $
#

DISTNAME=	gpsbabel-1.3.4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsbabel/}

MAINTAINER=	uli@habel.name
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
