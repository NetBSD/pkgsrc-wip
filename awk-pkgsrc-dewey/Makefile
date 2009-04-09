# $NetBSD: Makefile,v 1.5 2009/04/09 01:25:43 jsonn Exp $

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
#TEST_TARGET=		test # needs wip/runawk

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	share/runawk

WRKSRC=		${.CURDIR}/files
USE_LANGUAGES=	# empty
NO_BUILD=	yes

MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk

INSTALLATION_DIRS+=	share/runawk share/doc/awk-pkgsrc-dewey

.include "../../mk/bsd.pkg.mk"
