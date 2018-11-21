# $NetBSD$

MODULENAME=	Image_TIFF
INTERNAL_MODULENAME= _Image_TIFF
PIKEVERSUFFIX=	8.0

EXTRACT_ELEMENTS+= ${DISTNAME}/src/modules/Image

.include 	"../../lang/pike${PIKEVERSUFFIX}/builtin_module.mk"

PIKE_MODULE_OVERLAPPING_FILES+= lib/pike${PIKEVERSUFFIX}/modules/_Image_TIFF.pmod

# the Image_Freetype module uses headers from the Image module, but these aren't installed
# by default, so we just make them available
pre-build:
	cd ${WRKSRC} && ${MKDIR} src/post_modules/${INTERNAL_MODULENAME}/modules/Image && \
	  cp -r src/modules/Image/*.h src/post_modules/${INTERNAL_MODULENAME}/modules/Image

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
