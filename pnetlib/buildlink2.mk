# $NetBSD: buildlink2.mk,v 1.1 2003/07/18 17:22:04 poppnk Exp $
#
# This Makefile fragment is included by packages that use pnetlib.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(PNETLIB_BUILDLINK2_MK)
PNETLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pnetlib
BUILDLINK_DEPENDS.pnetlib?=		pnetlib>=0.5.8
BUILDLINK_PKGSRCDIR.pnetlib?=		../../wip/pnetlib

EVAL_PREFIX+=	BUILDLINK_PREFIX.pnetlib=pnetlib
BUILDLINK_PREFIX.pnetlib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Accessibility.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/DotGNU.SSL.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N-handlers.def
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.CJK.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.MidEast.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.Other.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.Rare.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.West.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/I18N.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.JScript.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.VisualBasic.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.VisualC.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Microsoft.Vsa.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/OpenSystem.C.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Drawing.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Net.IrDA.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Windows.Forms.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.Xml.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/System.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/Xsharp.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/cscompmgd.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/cstest.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/I18N.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.Xml.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/System.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/de/mscorlib.resources.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/libXsharpSupport.*
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/mscorlib.dll
BUILDLINK_FILES.pnetlib+=	lib/cscc/lib/pnetlib.here

BUILDLINK_TARGETS+=	pnetlib-buildlink

pnetlib-buildlink: _BUILDLINK_USE

.endif	# PNETLIB_BUILDLINK2_MK
