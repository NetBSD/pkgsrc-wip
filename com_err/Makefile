# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:55 asau Exp $

DISTNAME=	${E2FSPROGS_DISTNAME}
PKGREVISION=	1
# what should the version be?
PKGNAME=	com_err-${E2FSPROGS_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/lib/et
CATEGORIES=	devel
# probably MASTER_SITES should be defined in the e2fsprogs/Makefile.common
MASTER_SITES=	${E2FSPROGS_MASTER_SITES}

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Common Error Description Library

CONFLICTS+=	e2fsprogs<=1.35

PKG_DESTDIR_SUPPORT=	none

TEST_TARGET=	check

do-configure:
	cd ${WRKSRC}/../../ && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

.include "../../wip/e2fsprogs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
