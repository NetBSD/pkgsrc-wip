# $NetBSD: Makefile,v 1.3 2013/06/08 11:49:14 othyro Exp $

DATESTAMP=	20130603
DISTNAME=	libclocale-experimental-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-experimental//1}
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSNVJabTctdi1qblE/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libclocale/
COMMENT=	Library for cross-platform C locale functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libclocale-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libclocale.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
