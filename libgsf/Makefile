# $NetBSD: Makefile,v 1.1.1.1 2003/05/12 21:48:01 jeremy-c-reed Exp $

DISTNAME=		libgsf-1.8.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgsf/1.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=
COMMENT=		GNOME Structured File Library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
