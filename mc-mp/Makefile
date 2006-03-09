# $NetBSD: Makefile,v 1.3 2006/03/09 11:19:27 ghen Exp $
#

DISTNAME=		mc-4.1.40-pre9
PKGNAME=		mc-mp-4.1.39.99.9
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://mc.linuxinside.com/Releases/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://mc.linuxinside.com/cgi-bin/dir.cgi
COMMENT=		Midnight Commander clone

CONFLICTS+=		mc-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
INSTALL_MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

REPLACE_PERL+=		vfs/extfs/a vfs/extfs/deb vfs/extfs/mailfs

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	/bin/bash
_REPLACE.bash.new=	${SH:Q}
_REPLACE_FILES.bash=	vfs/extfs/iso

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SUBST+=		IF_LINUX=""
.else
PLIST_SUBST+=		IF_LINUX="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
