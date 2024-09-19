# $NetBSD: Makefile,v 1.4 2014/02/03 09:17:58 othyro Exp $

DISTNAME=	libcsplit-alpha-20150101
GITHUB_PROJECT=	libcsplit
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcsplit
COMMENT=	Library for cross-platform C split string functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcsplit.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
