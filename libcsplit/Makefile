# $NetBSD: Makefile,v 1.4 2014/02/03 09:17:58 othyro Exp $

DATESTAMP=	20140105
DISTNAME=	libcsplit-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	textproc
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSeE44MVpGWnpNeVU/

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
