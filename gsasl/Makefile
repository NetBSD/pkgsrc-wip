# $NetBSD: Makefile,v 1.1.1.1 2003/10/30 09:52:23 xtraeme Exp $
#

DISTNAME=		gsasl-0.0.8
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gsasl/releases/ \
			${MASTER_SITE_GNU:=gsasl/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gsasl/
COMMENT=		GNU implementation of the Simple Authentication and Security Layer

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

INFO_FILES=		gsasl.info

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libgsasl.pc.in

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../wip/libidn/buildlink2.mk"
.include "../../wip/libntlm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
