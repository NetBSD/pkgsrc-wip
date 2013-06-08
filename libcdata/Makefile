# $NetBSD: Makefile,v 1.1 2013/06/08 12:37:42 othyro Exp $

DATESTAMP=	20130407
DISTNAME=	libcdata-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSRzFtamhtVUlwYm8/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libcdata/
COMMENT=	Library for cross-platform C generic data functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcdata-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcdata.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
