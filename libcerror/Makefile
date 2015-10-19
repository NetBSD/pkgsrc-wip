# $NetBSD: Makefile,v 1.6 2014/02/03 09:10:41 othyro Exp $
#

DISTNAME=	libcerror-alpha-20150407
GITHUB_PROJECT=	libcerror
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcerror
COMMENT=	Library for cross-platform C error functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcerror.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
