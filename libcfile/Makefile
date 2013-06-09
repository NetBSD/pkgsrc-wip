# $NetBSD: Makefile,v 1.1 2013/06/09 21:56:24 othyro Exp $

DATESTAMP=	20130609
DISTNAME=	libcfile-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	sysutils
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSem41RXpvQkIyZlU/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcfile/
COMMENT=	Library for cross-platform C file functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcfile-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcfile.pc.in

.include "options.mk"

.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcnotify/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
