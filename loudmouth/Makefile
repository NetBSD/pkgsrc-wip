# $NetBSD: Makefile,v 1.2 2003/07/14 12:14:52 xtraeme Exp $
#

DISTNAME=	loudmouth-0.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/0.11/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.imendio.com/projects/loudmouth/
COMMENT=	Lightweight Jabber client library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-debug

HTMLDIR=		${PREFIX}/share/doc/html/loudmouth

pre-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/reference/html/* ${HTMLDIR}

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/gnutls/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
