# $NetBSD$
#
# This Makefile fragment defines how to users can specify something should
# be enabled and/or disabled. For example, you can test if a variable `FOO'
# is turned "on" like so:
#
#     .if defined(FOO) && !empty(FOO:M${YES})

.ifndef YESNO_MK
YESNO_MK=	# defined

YES=		[Yy][Ee][Ss]
NO=		[Nn][Oo]

.endif		# YESNO_MK
