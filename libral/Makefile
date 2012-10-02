# $NetBSD: Makefile,v 1.1 2012/10/02 19:51:30 othyro Exp $
#

DISTNAME=	libral-0.9.6
CATEGORIES=	misc
MASTER_SITES=	http://downloads.sourceforge.net/project/libral.berlios/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.berlios.de/projects/libral
COMMENT=	Address book engine
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config

PKGCONFIG_OVERRIDE+=	libral.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf


.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
