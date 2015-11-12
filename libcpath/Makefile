# $NetBSD: Makefile,v 1.3 2014/02/03 09:27:15 othyro Exp $

DISTNAME=	libcpath-alpha-20150101
GITHUB_PROJECT=	libcpath
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcpath
COMMENT=	Library for cross-platform C path functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
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
