# $NetBSD: Makefile,v 1.5 2012/12/25 09:44:08 ryo-on Exp $
#

DISTNAME=	fuse-google-drive-0
CATEGORIES=	filesystems
MASTER_SITES=	/usr/pkgsrc/distfiles/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	https://github.com/jcline/fuse-google-drive
COMMENT=	FUSE filesystem wrapper for Google Drive
LICENSE=	gplv2

GIT_REPOSITORIES=	fuse-google-drive
GIT_REPO.fuse-google-drive=	http://github.com/jcline/fuse-google-drive.git
GIT_REVISION.fuse-google-drive=	1e1bfa00b6d55cabcb717d0109ffc374c0af0348
.include "../../wip/mk/git-package.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal automake autoreconf gmake pkg-config
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${PKGBASE}

pre-configure:
	set -e; cd ${WRKSRC}; \
	autoreconf -vif

.include "../../mk/fuse.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
