# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 17:55:36 froz Exp $

DISTNAME=		shared-mime-info-0.12	
CATEGORIES=		misc
MASTER_SITES=	http://www.freedesktop.org/software/shared-mime-info/releases/

MAINTAINER=		froz@icix.org
COMMENT=		The freedesktop.org shared MIME database

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

MAKE_ENV+=  XDG_DATA_HOME=${LOCALBASE}/share
MAKE_ENV+=  XDG_DATA_DIRS=${LOCALBASE}/share

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
