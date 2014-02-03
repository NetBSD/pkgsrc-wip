# $NetBSD: Makefile,v 1.4 2014/02/03 09:48:00 othyro Exp $
#

DATESTAMP=	20140105
DISTNAME=	libbfio-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/alpha-//1}
CATEGORIES=	sysutils
MASTER_SITES=	http://googledrive.com/host/0B3fBvzttpiiSTERGV3V4bnZ3dlk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libbfio/
COMMENT=	Library to provide basic file input/output abstraction
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libbfio-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libbfio.pc.in

.include "options.mk"

.include "../../wip/libcthreads/buildlink3.mk"
.include "../../wip/libcfile/buildlink3.mk"
.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcpath/buildlink3.mk"
.include "../../wip/libcsplit/buildlink3.mk"
.include "../../wip/libcnotify/buildlink3.mk"
.include "../../wip/libcdata/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
