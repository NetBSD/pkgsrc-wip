# $NetBSD$
#
# This Makefile fragment standardizes where fonts are installed.
#
# It exposes the following variables:
#
#     FONTDIR -- where fonts are installed.
#
#     TTF_FONTDIR -- where TTF fonts in particular are installed.
#

.ifndef FONTS_MK
FONTS_MK=	# defined

FONTDIR?=	${PREFIX}/share/fonts/X11
TTF_FONTDIR?=	${FONTDIR}/TTF

.endif # FONTS_MK
