# $NetBSD: Makefile,v 1.6 2014/02/03 09:25:39 othyro Exp $
#

DATESTAMP=	20140105
DISTNAME=	libuna-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/alpha-//1}
CATEGORIES=	converters
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSaXBjN1ZJVzVsbjQ/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libuna/
COMMENT=	Library to support Unicode and ASCII (byte string) conversions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libuna-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libuna.pc.in

.include "options.mk"

.include "../../wip/libcnotify/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
