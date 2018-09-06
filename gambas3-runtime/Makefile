# $NetBSD$

BUILD_DIRS=	main comp
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-runtime-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Gambas interpreter and basic runtime
BUILD_DEPENDS+=	gambas3-gb-qt4-${GB_VERSION}:../../wip/gambas3-gb-qt4

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
