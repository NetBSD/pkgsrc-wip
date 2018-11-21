# $NetBSD$

MODULENAME=	GTK2
PIKEVERSUFFIX=	8.0
MODULE_TYPE=	post_module

.include 	"../../lang/pike${PIKEVERSUFFIX}/builtin_module.mk"

CFLAGS+=	-I../..
EXTRACT_ELEMENTS+= ${DISTNAME}/src/modules/Image
PIKE_MODULE_OVERLAPPING_FILES+= lib/pike${PIKEVERSUFFIX}/modules/GTK2.pmod

# the GTK2 module uses headers from the Image module, but these aren't installed
# by default, so we just make them available
pre-build:
	cd ${WRKSRC} && ${MKDIR} src/post_modules/${INTERNAL_MODULENAME}/modules/Image && \
	  cp -r src/modules/Image/*.h src/post_modules/${INTERNAL_MODULENAME}/modules/Image

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
