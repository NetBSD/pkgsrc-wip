# $NetBSD$

.include "../../wip/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-courier-imap-${VERSION}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (Courier authentication)
LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-courier-imap

BUILD_DIRS=		lib authenticate
INSTALL_DIRS=		authenticate
INSTALL_TARGET=		install-authlibPROGRAMS

.include "../../mk/bsd.pkg.mk"
