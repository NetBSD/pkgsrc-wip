# $NetBSD: Makefile,v 1.4 2004/11/24 15:50:01 thomasklausner Exp $
#

DISTNAME=	gob2-2.0.11
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
