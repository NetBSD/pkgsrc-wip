# $NetBSD: Makefile,v 1.2 2008/03/30 19:05:21 cheusov Exp $

DISTNAME=	awk-pkgsrc-dewey-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Pkgsrc dewey module for AWK programming language

DEPENDS+=	runawk-[0-9]*:../../wip/runawk

.include "../../wip/awk-pkgsrc-dewey/files/Makefile.version"

USE_BSD_MAKEFILE=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	share/runawk

WRKSRC=		${.CURDIR}/files
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk

INSTALLATION_DIRS+=	share

.include "../../mk/bsd.pkg.mk"
