# $NetBSD$

BUILD_DIRS=	main
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-runtime-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Gambas interpreter and basic runtime

CHECK_FILES_SKIP+=	${PREFIX}/lib/gambas3/gb.a
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.clipper.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.complex.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.compress.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.data.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.db.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.image.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.inotify.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.jit.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.la
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.option.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.signal.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.so.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.term.*
CHECK_FILES_SKIP+=	${PREFIX}/.*/gambas3/.*gb.vb.*

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
