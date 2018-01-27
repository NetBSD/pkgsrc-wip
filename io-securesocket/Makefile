# $NetBSD: Makefile,v 1.4 2012/11/13 22:25:33 othyro Exp $

.include "../../wip/io-base/version.mk"

PKGNAME=		io-securesocket-${IO_VERSION}
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		SSL socket addon for Io

ADDON_NAME=			Socket

.include "../../wip/io-base/addon.mk"

SUBST_CLASSES+=				enable-securesocket
SUBST_STAGE.enable-securesocket=	pre-configure
SUBST_MESSAGE.enable-securesocket=	Enabling SecureSocket addon
SUBST_FILES.enable-securesocket=	addons/CMakeLists.txt
SUBST_SED.enable-securesocket=		-e 's,^\# pkgsrc_disabled add_subdirectory(SecureSocket),add_subdirectory(SecureSocket),g'

INSTALL_DIRS+=		addons/Socket addons/SecureSocket

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
