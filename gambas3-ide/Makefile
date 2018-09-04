# $NetBSD$

BUILD_DIRS=	app
GB_DEPENDS=	gambas3-runtime gambas3-devel gambas3-gb-clipper gambas3-gb-db
GB_DEPENDS+=	gambas3-gb-db-form gambas3-gb-desktop gambas3-gb-desktop-x11
GB_DEPENDS+=	gambas3-gb-eval-highlight gambas3-gb-form gambas3-gb-form-dialog
GB_DEPENDS+=	gambas3-gb-form-editor gambas3-gb-form-mdi gambas3-gb-form-stock
GB_DEPENDS+=	gambas3-gb-form-terminal gambas3-gb-image gambas3-gb-markdown
GB_DEPENDS+=	gambas3-gb-net gambas3-gb-net-curl gambas3-gb-settings
GB_DEPENDS+=	gambas3-gb-signal gambas3-gb-term gambas3-gb-util
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-ide-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Integrated Development Environment for the Gambas programming language

CHECK_FILES_SKIP+=	${PREFIX}/bin/gb.*

.include "../../mk/bsd.pkg.mk"
