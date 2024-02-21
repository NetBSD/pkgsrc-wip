# $NetBSD$

.include "../../wip/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-courier-imap-${VERSION}

CONFIGURE_ARGS+=	--enable-courier-imap

BUILD_DIRS=		lib authenticate
INSTALL_DIRS=		authenticate
INSTALL_TARGET=		install-authlibPROGRAMS

.include "../../mk/bsd.pkg.mk"
