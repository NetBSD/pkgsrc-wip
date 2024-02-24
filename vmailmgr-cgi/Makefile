# $NetBSD$

.include "../../wip/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-cgi-${VERSION}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (cgi programs)
LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-cgi

BUILD_DIRS=		lib cgi
INSTALL_DIRS=		cgi

.include "../../mk/bsd.pkg.mk"
