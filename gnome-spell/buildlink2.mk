# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/16 07:55:17 bseklecki Exp $
#
# This Makefile fragment is included by packages that use gnome-spell.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(GNOME_SPELL_BUILDLINK2_MK)
GNOME_SPELL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-spell
BUILDLINK_DEPENDS.gnome-spell?=		gnome-spell>=1.0.5
BUILDLINK_PKGSRCDIR.gnome-spell?=		../../textproc/gnome-spell

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-spell=gnome-spell
BUILDLINK_PREFIX.gnome-spell_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-spell+=	lib/bonobo/servers/GNOME_Spell.server
BUILDLINK_FILES.gnome-spell+=	share/idl/Spell.idl
BUILDLINK_FILES.gnome-spell+=	lib/gnome-spell/libgnome-spell-component-0.3.*
BUILDLINK_FILES.gnome-spell+=	lib/gnome-spell/libgnome-spell-component.*

.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-spell-buildlink

gnome-spell-buildlink: _BUILDLINK_USE

.endif	# GNOME_SPELL_BUILDLINK2_MK
