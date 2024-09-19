# $NetBSD: Makefile,v 1.2 2014/02/03 09:13:31 othyro Exp $

DISTNAME=	libcdata-alpha-20150104
GITHUB_PROJECT=	libcdata
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcdata/
COMMENT=	Library for cross-platform C generic data functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcdata.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
