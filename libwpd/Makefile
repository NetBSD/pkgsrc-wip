# $NetBSD: Makefile,v 1.10 2005/04/11 21:13:51 tvierling Exp $

DISTNAME=	libwpd-0.7.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
