# $NetBSD: buildlink2.mk,v 1.2 2004/01/04 06:21:54 mpasternak Exp $
#
# This Makefile fragment is included by packages that use kyra.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(KYRA_BUILDLINK2_MK)
KYRA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kyra
BUILDLINK_DEPENDS.kyra?=		kyra>=1.6.5
BUILDLINK_PKGSRCDIR.kyra?=		../../wip/kyra

EVAL_PREFIX+=	BUILDLINK_PREFIX.kyra=kyra
BUILDLINK_PREFIX.kyra_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kyra+=	include/Kyra/engine/action.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/box.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/boxresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/canvas.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/canvasresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/color.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/dataresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/dirtyrectangle.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/encoder.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/engine.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/fontresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/image.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/imagecontainer.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/imagenode.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/imagetree.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/imnode.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/krmath.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/kyra.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/kyrabuild.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/kyraresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/namefield.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/ogltexture.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/painter.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/parser.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/pixelblock.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/rle.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/sdlutil.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/sprite.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/spriteresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/tags.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/textbox.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/tile.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/tileresource.h
BUILDLINK_FILES.kyra+=	include/Kyra/engine/vault.h
BUILDLINK_FILES.kyra+=	include/Kyra/kyra.h
BUILDLINK_FILES.kyra+=	include/Kyra/tinyxml/tinyxml.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glcirclelist.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/gldebug.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/gldynarray.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glfixed.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glgraph.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glinsidelist.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glintarrayset.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glisomath.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/gllist.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glmap.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glmemorypool.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glperformance.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glprime.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glrandom.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glstack.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glstring.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/gltypes.h
BUILDLINK_FILES.kyra+=	include/Kyra/util/glutil.h
BUILDLINK_FILES.kyra+=	lib/libkyra.*

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.if exists(../../mk/opengl.buildlink2.mk)
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/MesaLib/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	kyra-buildlink

kyra-buildlink: _BUILDLINK_USE

.endif	# KYRA_BUILDLINK2_MK
