# $NetBSD$

BUILD_DIRS=	main/gbc
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-devel-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Gambas compilation tools

USE_TOOLS+=	make

pre-build:
	set -e; cd ${WRKSRC}/main; \
	make trunk_version.h

.include "../../mk/bsd.pkg.mk"
