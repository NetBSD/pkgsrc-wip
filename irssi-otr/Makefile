# $NetBSD: Makefile,v 1.1 2015/08/02 09:44:46 rhialto Exp $

DISTNAME=		irssi-otr-1.01
PKGREVISION=		1
CATEGORIES=		chat
GIT_REPO=		git://github.com/cryptodotis/irssi-otr.git
# v1.01 is not tagged; use a version slightly after that.
#GIT_REVISION.github=	4ad3b7b6c85be0154ab3694fe9831796db20c4fe
# libotr >= 4.1.0 in configure.ac and spec file; Jan 12, 2015
GIT_REVISION=		f75eb260c168b708873f2770d95b9a1b66144edd

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		https://github.com/cryptodotis/irssi-otr
COMMENT=		Libotr (https://otr.cypherpunks.ca) support for Irssi
LICENSE=		gnu-gpl-v2

DEPENDS+=		irssi>=0.8.15:../../chat/irssi

USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix=${BUILDLINK_PREFIX.irssi}
CONFIGURE_ARGS+=	--with-irssi-headers=${BUILDLINK_PREFIX.irssi}
CONFIGURE_ARGS+=	--with-irssi-module-dir=${BUILDLINK_PREFIX.irssi}/lib/irssi/modules

# Since there is no chat/irssi/buildlink3.mk, we have to base our
# BUILDLINK_PREFIX.irssi on something else.
BUILDLINK_PREFIX.irssi=	${PREFIX}

# Also we need to access the irssi header files
post-wrapper:
	cd ${WRKDIR}/.buildlink/include && ln -s ${BUILDLINK_PREFIX.irssi}/include/irssi .

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
