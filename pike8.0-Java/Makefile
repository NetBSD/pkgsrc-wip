# $NetBSD$

.include "../../mk/bsd.prefs.mk"

MODULENAME=	Java
PIKEVERSUFFIX=	8.0

USE_JAVA=       yes
USE_JAVA2= 7

.include 	"../../lang/pike${PIKEVERSUFFIX}/builtin_module.mk"

PIKE_MODULE_OVERLAPPING_FILES+= lib/pike${PIKEVERSUFFIX}/modules/Java.pmod

EXTRACT_ELEMENTS = ${DISTNAME}/src/modules/${MODULENAME} ${DISTNAME}/refdoc

.include "../../devel/libffi/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../mk/java-vm.mk"
.endif
.include "../../mk/bsd.pkg.mk"
