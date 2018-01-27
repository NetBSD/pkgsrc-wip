# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:37 thomasklausner Exp $
#

DISTNAME=	mlocate-0.24
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/mlocate/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	https://pagure.io/mlocate
COMMENT=	Merging 'locate' implementation
LICENSE=	gnu-gpl-v2

# Depends on _PATH_MOUNTED being defined in paths.h
ONLY_FOR_PLATFORM=	Linux-*-*

CONFLICTS=	slocate-[0-9]*

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.

GNU_CONFIGURE=	yes

PKG_GROUPS=	mlocate

SPECIAL_PERMS+=	bin/locate root mlocate 2755

BUILD_DEFS+=	VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

OWN_DIRS+=	${VARBASE}/mlocate

.include "../../mk/bsd.pkg.mk"
