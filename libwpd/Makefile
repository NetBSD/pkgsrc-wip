# $NetBSD: Makefile,v 1.2 2003/06/11 08:25:24 thomasklausner Exp $

DISTNAME=	libwpd-0.4.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	library for importing and exporting WordPerfect(tm) documents

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../wip/libgsf/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
