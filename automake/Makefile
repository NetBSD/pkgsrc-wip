# $NetBSD: Makefile,v 1.120 2023/01/05 14:42:13 wiz Exp $
#
# for major version updates, don't forget adding new links in
# mk/tools/automake.mk

DISTNAME=	automake-1.18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}
MASTER_SITES+=	ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator
LICENSE=	gnu-gpl-v2

AUTOCONF_REQD+=	2.62
USE_TOOLS+=	autoconf gm4:run perl:run

PLIST_SUBST+=		PKG_DIR_VERSION=1.18
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none
INFO_FILES=		YES

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
