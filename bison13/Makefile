# $NetBSD: Makefile,v 1.7 2006/10/27 17:51:40 shattered Exp $
# $Id: Makefile,v 1.7 2006/10/27 17:51:40 shattered Exp $
#

DISTNAME=		bison-1.35
PKGNAME=		${DISTNAME:S/-/13-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		Package for old version of GNU yacc(1) replacement

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-suffix=-1.35
USE_TOOLS+=		gm4:run msgfmt

INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
