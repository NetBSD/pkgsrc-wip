# $NetBSD: Makefile,v 1.3 2003/07/17 23:56:12 xtraeme Exp $
#

DISTNAME=	loudmouth-0.12
CATEGORIES=	devel
MASTER_SITES=	http://www.imendio.com/projects/loudmouth/src/

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

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LOUDMOUTH_USE_SSL

.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
.include "../../security/gnutls/buildlink2.mk"
.endif

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
