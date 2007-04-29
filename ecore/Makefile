# $NetBSD: Makefile,v 1.8 2007/04/29 12:51:35 grzela1 Exp $
#

DISTNAME=	ecore-0.9.9.037
CATEGORIES=	x11
MASTER_SITES=	http://enlightenment.freedesktop.org/files/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	grzela@seculture.com
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Event Abstraction and Modular Convenience Library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
DEPENDS+=	evas>=0.9.9.037:../../wip/evas
DEPENDS+=	libXdamage>=1.1.1:../../x11/libXdamage
DEPENDS+=	libXp>=1.0.0:../../x11/libXp
DEPENDS+=	libXScrnSaver>=1.1.2:../../x11/libXScrnSaver
DEPENDS+=	curl>=7.16.2:../../www/curl
.include	"../../wip/evas/buildlink3.mk"
.include	"../../x11/libXdamage/buildlink3.mk"
.include	"../../x11/libXp/buildlink3.mk"
.include	"../../x11/libXScrnSaver/buildlink3.mk"
.include	"../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
