# $NetBSD: Makefile,v 1.8 2004/08/17 18:30:26 tvierling Exp $

DISTNAME=	libwpd-0.7.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LIBTOOL_LA_FILES+=	lib/libwpd-1.la
USE_GNU_TOOLS+=	make

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
