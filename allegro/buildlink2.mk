# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/06 11:17:20 thomasklausner Exp $
#

.if !defined(ALLEGRO_BUILDLINK2_MK)
ALLEGRO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		allegro
BUILDLINK_DEPENDS.allegro?=	allegro>=4.1.8
BUILDLINK_PKGSRCDIR.allegro?=	../../wip/allegro

EVAL_PREFIX+=	BUILDLINK_PREFIX.allegro=allegro
BUILDLINK_PREFIX.allegro_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.allegro+=	include/allegro.h
BUILDLINK_FILES.allegro+=	include/allegro/3d.h
BUILDLINK_FILES.allegro+=	include/allegro/3dmaths.h
BUILDLINK_FILES.allegro+=	include/allegro/alcompat.h
BUILDLINK_FILES.allegro+=	include/allegro/alinline.h
BUILDLINK_FILES.allegro+=	include/allegro/alunixac.h
BUILDLINK_FILES.allegro+=	include/allegro/base.h
BUILDLINK_FILES.allegro+=	include/allegro/color.h
BUILDLINK_FILES.allegro+=	include/allegro/compiled.h
BUILDLINK_FILES.allegro+=	include/allegro/config.h
BUILDLINK_FILES.allegro+=	include/allegro/datafile.h
BUILDLINK_FILES.allegro+=	include/allegro/debug.h
BUILDLINK_FILES.allegro+=	include/allegro/digi.h
BUILDLINK_FILES.allegro+=	include/allegro/draw.h
BUILDLINK_FILES.allegro+=	include/allegro/file.h
BUILDLINK_FILES.allegro+=	include/allegro/fix.h
BUILDLINK_FILES.allegro+=	include/allegro/fixed.h
BUILDLINK_FILES.allegro+=	include/allegro/fli.h
BUILDLINK_FILES.allegro+=	include/allegro/fmaths.h
BUILDLINK_FILES.allegro+=	include/allegro/gfx.h
BUILDLINK_FILES.allegro+=	include/allegro/graphics.h
BUILDLINK_FILES.allegro+=	include/allegro/gui.h
BUILDLINK_FILES.allegro+=	include/allegro/inline/3dmaths.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/asm.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/color.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/draw.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/file.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/fix.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/fmaths.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/gfx.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/matrix.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/rle.inl
BUILDLINK_FILES.allegro+=	include/allegro/inline/system.inl
BUILDLINK_FILES.allegro+=	include/allegro/internal/aintern.h
BUILDLINK_FILES.allegro+=	include/allegro/internal/aintvga.h
BUILDLINK_FILES.allegro+=	include/allegro/internal/alconfig.h
BUILDLINK_FILES.allegro+=	include/allegro/joystick.h
BUILDLINK_FILES.allegro+=	include/allegro/keyboard.h
BUILDLINK_FILES.allegro+=	include/allegro/matrix.h
BUILDLINK_FILES.allegro+=	include/allegro/midi.h
BUILDLINK_FILES.allegro+=	include/allegro/mouse.h
BUILDLINK_FILES.allegro+=	include/allegro/palette.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintbeos.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintdos.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintlnx.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintmac.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintqnx.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintunix.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aintwin.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/al386gcc.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/al386vc.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/al386wat.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/albcc32.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/albecfg.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/albeos.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aldjgpp.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/aldos.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/almac.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/almaccfg.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/almngw32.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/almsvc.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alplatf.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alqnx.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alqnxcfg.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alucfg.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alunix.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alunixac.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alwatcom.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/alwin.h
BUILDLINK_FILES.allegro+=	include/allegro/platform/macdef.h
BUILDLINK_FILES.allegro+=	include/allegro/quat.h
BUILDLINK_FILES.allegro+=	include/allegro/rle.h
BUILDLINK_FILES.allegro+=	include/allegro/sound.h
BUILDLINK_FILES.allegro+=	include/allegro/stream.h
BUILDLINK_FILES.allegro+=	include/allegro/system.h
BUILDLINK_FILES.allegro+=	include/allegro/text.h
BUILDLINK_FILES.allegro+=	include/allegro/timer.h
BUILDLINK_FILES.allegro+=	include/allegro/unicode.h
BUILDLINK_FILES.allegro+=	include/linalleg.h
BUILDLINK_FILES.allegro+=	include/xalleg.h
BUILDLINK_FILES.allegro+=	lib/liballd-*.*
BUILDLINK_FILES.allegro+=	lib/liballd.*
BUILDLINK_FILES.allegro+=	lib/liballd_unsharable.*
BUILDLINK_FILES.allegro+=	lib/liballeg-*.*
BUILDLINK_FILES.allegro+=	lib/liballeg.*
BUILDLINK_FILES.allegro+=	lib/liballeg_unsharable.*

BUILDLINK_TARGETS+=	allegro-buildlink

allegro-buildlink: _BUILDLINK_USE

.endif	# ALLEGRO_BUILDLINK2_MK
