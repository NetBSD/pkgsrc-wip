# $NetBSD: Makefile,v 1.2 2013/06/09 22:01:57 othyro Exp $

DATESTAMP=	20130609
DISTNAME=	libcpath-alpha-${DATESTAMP}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSOGFVQUwtOHlEWjQ/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libcpath/
COMMENT=	Library for cross-platform C path functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcpath-${DATESTAMP}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcpath.pc.in

.include "options.mk"

.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcsplit/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
