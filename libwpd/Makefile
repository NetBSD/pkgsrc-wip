# $NetBSD: Makefile,v 1.3 2003/07/02 09:28:04 thomasklausner Exp $

DISTNAME=	libwpd-0.4.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	library for importing and exporting WordPerfect(tm) documents

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
