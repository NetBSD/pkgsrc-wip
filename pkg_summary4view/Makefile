# $NetBSD: Makefile,v 1.3 2008/02/10 20:46:10 cheusov Exp $

.include "../../wip/pkg_summary4view/files/Makefile.version"

DISTNAME=	pkg_summary4view-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Convert summary information to human readable format

USE_BSD_MAKEFILE=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAN1DIR=	${PKGMANDIR}/man1
MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no

INSTALLATION_DIRS=	bin ${MAN1DIR}

.include "../../mk/bsd.pkg.mk"
