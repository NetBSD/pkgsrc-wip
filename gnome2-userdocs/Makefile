# $NetBSD: Makefile,v 1.2 2003/06/24 02:28:34 xtraeme Exp $
#

DISTNAME=	gnome2-user-docs-2.0.6
PKGNAME=	${DISTNAME:S/user-/user/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome2-user-docs/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	The GNOME 2 users guide

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
