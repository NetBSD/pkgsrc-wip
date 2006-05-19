# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:14 ykomatsu Exp $
# $Id: Makefile,v 1.6 2006/05/19 16:51:14 ykomatsu Exp $
#

DISTNAME=		bison-1.35
PKGNAME=		${DISTNAME:S/-/13-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		Package for old version of GNU yacc(1) replacement

DEPENDS+=		m4>=1.4:../../devel/m4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	 --program-suffix=-1.35
USE_TOOLS+=		msgfmt

M4=			${LOCALBASE}/bin/gm4

INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
