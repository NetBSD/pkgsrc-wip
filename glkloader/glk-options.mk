# $NetBSD: glk-options.mk,v 1.1 2006/07/12 23:18:22 dillo Exp $

PKG_OPTIONS_REQUIRED_GROUPS+=	glk
PKG_OPTIONS_GROUP.glk=		glkloader glkterm gtkglk
PKG_SUGGESTED_OPTIONS+=		glkloader
