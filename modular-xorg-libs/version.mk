# $NetBSD: version.mk,v 1.2 2006/11/10 18:08:25 jeremy-c-reed Exp $
#
# This Makefile fragment is included by Makefiles that need to access
# the X11_TYPE and version number of a "modular" X.org distribution.
#
# The following variables are provided by this file:
#
#    BUILTIN_X11_TYPE.modular is the X11_TYPE of the modular X.org
#	distribution and is "modular".
#
#    BUILTIN_X11_VERSION.modular is the version number of the
#	modular X.org distribution detected on the system.
#

BUILTIN_X11_TYPE.modular=	modular
BUILTIN_X11_VERSION.modular=	7.0  ## need to do this
