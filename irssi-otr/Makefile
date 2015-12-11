# $NetBSD: Makefile,v 1.1 2015/08/02 09:44:46 rhialto Exp $

DISTNAME=		irssi-otr-1.01
CATEGORIES=		chat

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		https://github.com/cryptodotis/irssi-otr
COMMENT=		Libotr (https://otr.cypherpunks.ca) support for Irssi
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	github
GIT_REPO.github= 	git://github.com/cryptodotis/irssi-otr.git
GIT_MODULE.github=	irssi-otr
# v1.01 is not tagged; use a version slightly after that.
GIT_REVISION.github=	4ad3b7b6c85be0154ab3694fe9831796db20c4fe

WRKSRC=			${WRKDIR}/${PKGBASE}

USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		automake
USE_TOOLS+=		autoconf
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix=${BUILDLINK_PREFIX.irssi}
CONFIGURE_ARGS+=	--with-irssi-module-dir=${BUILDLINK_PREFIX.irssi}/lib/irssi/modules

DEPENDS+=		irssi>=0.8.15:../../chat/irssi

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
