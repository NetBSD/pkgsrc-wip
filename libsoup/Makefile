# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 21:18:06 marc Exp $
#

DISTNAME=		libsoup-1.99.26
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libsoup/1.99/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		HTTP library implementation in C

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/soup-2.0.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
