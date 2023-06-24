# $NetBSD: Makefile,v 1.2 2015/02/15 11:35:30 nros Exp $

DISTNAME=	mozjpeg-${VERSION}-release-source
PKGNAME=	${DISTNAME:S/-release-source//}
VERSION=	3.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mozilla/mozjpeg/releases/download/v${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/mozjpeg/
COMMENT=	Mozilla JPEG Encoder Project
LICENSE=	modified-bsd

TOOL_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

WRKSRC=		${WRKDIR}/mozjpeg

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes


.include "../../mk/bsd.pkg.mk"
