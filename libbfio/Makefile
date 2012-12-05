# $NetBSD: Makefile,v 1.1 2012/12/05 04:40:20 othyro Exp $
#

DISTNAME=	libbfio-alpha-20120425
PKGNAME=	${DISTNAME:S/alpha-//1}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libbfio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libbfio.sourceforge.net/
COMMENT=	Library to provide basic file input/output abstraction
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libbfio-20120425
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libbfio.pc.in

.include "options.mk"

#BUILDLINK_API_DEPENDS.libuna+=	libuna>=20120630
.include "../../wip/libuna/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
