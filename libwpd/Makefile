# $NetBSD: Makefile,v 1.6 2004/03/04 15:57:27 jeremy-c-reed Exp $

DISTNAME=	libwpd-0.7.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
