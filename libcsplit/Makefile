# $NetBSD: Makefile,v 1.2 2013/06/08 12:24:12 othyro Exp $

DATESTAMP=	20121224
DISTNAME=	libcsplit-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	textproc
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSeE44MVpGWnpNeVU/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcsplit/
COMMENT=	Library for cross-platform C split string functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcsplit-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcsplit.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
