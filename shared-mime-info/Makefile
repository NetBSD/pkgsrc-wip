# $NetBSD: Makefile,v 1.1.1.2 2003/12/04 22:23:05 anielski Exp $
#

DISTNAME=		shared-mime-info-0.12
CATEGORIES=		sysutils
MASTER_SITES=   ${HOMEPAGE}releases/

MAINTAINER=		aniou@smutek.pl
HOMEPAGE=		http://www.freedesktop.org/software/shared-mime-info/
COMMENT=		large number of common MIME types

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
