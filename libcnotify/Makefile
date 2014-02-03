# $NetBSD: Makefile,v 1.4 2014/02/03 09:23:21 othyro Exp $

DATESTAMP=	20140105
DISTNAME=	libcnotify-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	sysutils
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSb0xsMGNocEtGUjQ/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcnotify/
COMMENT=	Library to support cross-platform C notification functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcnotify-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcnotify.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
