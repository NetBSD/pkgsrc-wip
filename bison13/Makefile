# $NetBSD: Makefile,v 1.3 2005/07/27 16:25:04 thomasklausner Exp $
# $Id: Makefile,v 1.3 2005/07/27 16:25:04 thomasklausner Exp $
#

DISTNAME=		bison-1.35
PKGNAME=		${DISTNAME:S/-/13-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		Package for old version of GNU yacc(1) replacement

DEPENDS+=		m4>=1.4:../../devel/m4
BUILD_USES_MSGFMT=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	 --program-suffix=-1.35

M4=			${LOCALBASE}/bin/gm4

INFO_FILES=		bison.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
